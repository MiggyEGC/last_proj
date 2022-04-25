#include <stdio.h>
#include <assert.h>
#include "doubly_linked_list.h"

int main()
{
    list_t *list = create_empty_list();
    insert_at_head(list, 56);

    insert_at_head(list, 40);
    insert_at_tail(list, 78);
    insert_at_tail(list, 90);
    insert_in_order(list, 65);
   // node_t *test_node = find(*list, 90);
    print_list(*list);

}
