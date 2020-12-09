//
// Created by rienel on 26.03.18.
//

#include <random>
#include "Array.h"

bool *Array::getArray() const {
    return array;
}

void Array::setArray(bool *array) {
    Array::array = array;
}

int Array::getLength() const {
    return length;
}

void Array::setLength(int length) {
    Array::length = length;
}

Array::Array(bool *array, int length) {
    this->array = array;
    this->length = length;
}

Array::Array(int length) {
    this->length = length;
    this->array = new bool[this->length];
    int i;
    for (i = 0; i < this->length; i++) {
        this->array[i] = static_cast<bool>(random() % 2);
    }
}

Array::Array(Array *pArray) {
    this->length = pArray->getLength();
    delete[] this->array;
    this->array = new bool[this->length];
    for (int i = 0; i < this->length; ++i) {
        this->array[i] = pArray->get(i);
    }
}

Array::~Array() {
    delete[] this->array;
}

bool Array::pop(int index) {
    bool returnedValue;
    if (index != -1) {
        returnedValue = this->array[index];
    } else {
        returnedValue = this->array[this->length - 1];
    }
    bool *buff = new bool[this->length - 1];
    for (int i = 0, j = 0; i < this->length; ++i) {
        if (i != index) {
            buff[j] = this->array[i];
            j++;
        }
    }
    delete[] this->array;
    this->array = buff;
    this->length--;
    return returnedValue;
}

std::ostream &operator<<(std::ostream &out, Array **pArray) {
    for (int i = 0; i < (*pArray)->length; ++i) {
        std::cout << (*pArray)->array[i];
    }
    return out;
}

void Array::append(bool value, int index) {
    bool *buff = new bool[this->length + 1];
    if (index != -1) {
        for (int i = 0, j = 0; i < this->length + 1; ++i) {
            if (i == index) {
                buff[i] = value;
            } else {
                buff[i] = this->array[j];
                j++;
            }
        }
    } else {
        int i;
        for (i = 0; i < this->length; ++i) {
            buff[i] = this->array[i];
        }
        buff[i] = value;
    }
    delete[] this->array;
    this->array = buff;
    this->length++;
}

void Array::extend(Array **array) {
    bool *buff = new bool[this->length + (*array)->getLength()];
    int i;
    for (i = 0; i < this->length; ++i) {
        buff[i] = this->array[i];
    }
    for (int j = 0; j < (*array)->length; ++j) {
        buff[i++] = (*array)->get(j);
    }
    delete[] this->array;
    this->array = buff;
    this->length += (*array)->getLength();
}

bool Array::get(int index) {
    return this->array[index];
}

void Array::set(bool value, int index) {
    this->array[index] = value;
}

