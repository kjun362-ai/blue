#include <stdio.h>
#include <stdlib.h>


int main() {
    typedef struct {
        size_t capacity;//할당받은 크기
        size_t size;//사용하는 크기
        int* data;//할당받은 메모리 주소
    } dy_array;

    //effect : construct dy_array with capacity
    dy_array construct_dy_array(size_t capacity);



    //effect : destruct dy_array and free heap memory space
    void destruct_dy_array(dy_array* array);

    //effect : push back "value" to dy_array
    void dy_array_push(dy_array* array, int value);

    //effect : return idx`th value , when input idx is out of bound return 0;
    int dy_array_get(dy_array* array, int index);

    //effect : resize, reallocate data, when cap > new_cap, has no effect. return new_capacity
    int dy_array_resize(dy_array* array, size_t new_capacity);
}


