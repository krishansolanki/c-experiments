//
//  linked_list_test.c
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#include "tests.h"
#include "../linked_list/linked_list.c"


static void create_list_test(void **state) {
    create_list();
    
}

static void add_node_test() {
    add_node();
}

static void delete_node_test() {
    delete_node();
    
}

static void edit_node_test() {
    edit_node();
}

static void move_node_test() {
    move_node();
}

static void display_list_test() {
    display_list();
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(create_list_test),
        cmocka_unit_test(add_node_test),
        cmocka_unit_test(delete_node_test),
        cmocka_unit_test(edit_node_test),
        cmocka_unit_test(move_node_test),
        cmocka_unit_test(display_list_test),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
