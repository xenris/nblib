[Index](../index.hpp.md#index)

# Array

```c++
nblib::Array<int32_t, 6> array;

array[0] = 6;
array[1] = 8;
array[2] = 4;
array[3] = 5;
array[4] = 1;
array[5] = 2;

nblib::quicksort(array->begin(), array->size());

nblib::Array<int32_t>* pointer = &array;

int32_t n = pointer->get(0); // n = 1

pointer->fill(0);

for(auto n& : pointer) {
    n += 5;
}
```

## class Array<class Type, int size\>

#### Array()

## class Array<class Type\>

#### Array(Type\* buffer, int size)

#### void fill(Type t)

#### int size()

#### Type& operator \[\](int i)

#### Type& get(int i)

#### Array<Type\>& operator =(Array<Type\> other)

#### Type\* begin()

#### Type\* end()
