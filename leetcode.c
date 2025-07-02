#include "lib/dynamic_array/dynamic_array.h"
#include "lib/linked_lists/linked_lists.h"
#include "lib/strings/strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main() {
    DynamicArray *arr = create_array(5);
    print_array(arr);
    for (int i = 0; i < 5; i++) {
        insert(arr, i, i);
    }
    reverse_arr(arr);
    print_array(arr);
    free_array(arr);

    String *hello = str("Hello!");
    print_str(hello);
    upper(hello);
    print_str(hello);

    free_str(hello);

    return 0;
}