#include <iostream>
#include <random>
#include "Array.h"

Array *crcFind(Array **sequence, Array **polynom);

Array *crcCheck(Array **sequence, Array **polynom, Array **crc);

void addZeros(Array **pArray, int zero_length);

int main() {
//    bool polynom[] = {true, false, false, false, false, true, true}; // CRC-6-ITU
    int sequence_length = 10;
    int polynom_length = 7;
    Array *sequence = new Array(10);
//    sequence->set(true, 0);
//    sequence->set(true, 1);
//    sequence->set(false, 2);
//    sequence->set(true, 3);
//    sequence->set(false, 4);
//    sequence->set(true, 5);
//    sequence->set(true, 6);
//    sequence->set(false, 7);
//    sequence->set(true, 8);
//    sequence->set(true, 9);
//    Array *polynom = new Array(5); // CRC-4-ITU
//    polynom->set(true, 0);
//    polynom->set(false, 1);
//    polynom->set(false, 2);
//    polynom->set(true, 3);
//    polynom->set(true, 4);
    Array *polynom = new Array(7);
    polynom->set(true, 0);
    polynom->set(false, 1);
    polynom->set(false, 2);
    polynom->set(false, 3);
    polynom->set(false, 4);
    polynom->set(true, 5);
    polynom->set(true, 6);
    std::cout << &polynom << "\n";
    std::cout << &sequence << "\n";
//    sequence->extend(&polynom);
//    std::cout << &sequence << "\n";
//    std::cout << sequence->getLength() << "\n";
    Array *crc = crcFind(&sequence, &polynom);
    std::cout << &crc << "\n";
    Array *crc_checked = crcCheck(&sequence, &polynom, &crc);

    delete sequence;
    delete polynom;
    delete crc;
    delete crc_checked;
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
    for (int i = 0, j = 0; i < copySequence->getLength() - (*polynom)->getLength(); ++i) {
        if (reg->get(0)) {
            for (j = 0; j < (*polynom)->getLength(); ++j) {
                reg->set(reg->get(j) ^ (*polynom)->get(j), j);
            }
        }
        reg->pop(0);
        reg->append(copySequence->get(i + (*polynom)->getLength()));
    }
    reg->pop(0);
    return reg;
}

Array *crcCheck(Array **sequence, Array **polynom, Array **crc) {
    (*sequence)->extend(crc);
    Array *crcForValidate = crcFind(&(*sequence), &(*polynom));
    std::cout << &crcForValidate << "\n";
    delete crcForValidate;
//    delete crc_crc;
}

void addZeros(Array **pArray, int zero_length) {
    for (int i = 0; i < zero_length; i++) {
        (*pArray)->append(false);
    }
}
