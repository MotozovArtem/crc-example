#include <iostream>
#include <random>
#include "../include/Array.h"

Array *crcFind(Array **sequence, Array **polynom);

void crcCheck(Array **sequence, Array **polynom, Array **crc);

void addZeros(Array **pArray, int zero_length);

int main() {
//    bool polynom[] = {true, false, false, false, false, true, true}; // CRC-6-ITU
    Array *sequence = new Array(10);
    Array *polynom = new Array(7);
    polynom->set(true, 0);
    polynom->set(false, 1);
    polynom->set(false, 2);
    polynom->set(false, 3);
    polynom->set(false, 4);
    polynom->set(true, 5);
    polynom->set(true, 6);
    std::cout << "Polynom=" << &polynom << "\n";
    std::cout << "Sequence=" << &sequence << "\n";
    Array *crc = crcFind(&sequence, &polynom);
    std::cout << "CRC=" << &crc << "\n";
    crcCheck(&sequence, &polynom, &crc);

    delete sequence;
    delete polynom;
    delete crc;
    return 0;
}

Array *crcFind(Array **sequence, Array **polynom) {
    Array *reg = new Array((*polynom)->getLength());
    for (int i = 0; i < (*polynom)->getLength(); ++i) {
        reg->set((*sequence)->get(i), i);
    }
    Array *copySequence = new Array(*sequence);
    addZeros(&copySequence, (*polynom)->getLength() - 1);
    std::cout << &copySequence << "\n";
    for (int i = 0, j = 0; i < copySequence->getLength() - (*polynom)->getLength()+1; ++i) {
        if (reg->get(0)) {
            for (j = 0; j < (*polynom)->getLength(); ++j) {
                reg->set(reg->get(j) ^ (*polynom)->get(j), j);
            }
        }
        reg->pop(0);
        reg->append(copySequence->get(i + (*polynom)->getLength()));
    }
    if (!reg->get(0)) {
        reg->pop(0);
    }
    return reg;
}

void crcCheck(Array **sequence, Array **polynom, Array **crc) {
    (*sequence)->extend(crc);
    Array *crcForValidate = crcFind(&(*sequence), &(*polynom));
    std::cout << &crcForValidate << "\n";
    delete crcForValidate;
}

void addZeros(Array **pArray, int zero_length) {
    for (int i = 0; i < zero_length; i++) {
        (*pArray)->append(false);
    }
}
