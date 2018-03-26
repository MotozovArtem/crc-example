//
// Created by rienel on 26.03.18.
//

#ifndef LAB3_IPK_ARRAY_H
#define LAB3_IPK_ARRAY_H

#include <iostream>

class Array {
private:
    bool *array;
    int length;
public:
    Array(bool *array, int length);

    Array(int length);

    Array(Array *pArray);

    ~Array();

    bool *getArray() const;

    void setArray(bool *array);

    int getLength() const;

    void setLength(int length);

    bool pop(int index = -1);

    void append(bool value, int index = -1);

    void extend(Array **array);

    bool get(int index);

    void set(bool value, int index);

    friend std::ostream &operator<<(std::ostream &out, Array **pArray);
};


#endif //LAB3_IPK_ARRAY_H
