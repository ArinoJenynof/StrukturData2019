#include <stdio.h>
#include <stdlib.h>
#include "ETS.h"

int main()
{
    struct linklist list1, list2, list_merged;
    list1.head = list1.tail = NULL;
    list2.head = list2.tail = NULL;
    list_merged.head = list_merged.tail = NULL;
    char dir[256], c;
    printf("Input 1st filename > ");
    scanf("%s", dir);
    input_data(&list1, dir);

    printf("Input 2nd filename > ");
    scanf("%s", dir);
    input_data(&list2, dir);

    merge_list(&list1, &list2, &list_merged);
    print_list(&list1);
    printf("\n");
    print_list(&list2);
    printf("\n");
    print_list(&list_merged);
    printf("\n\n");
    printf("Press any key to continue . . .");
    getchar();
    while (scanf("%c", &c) == 1)
        break;
    return 0;
}
