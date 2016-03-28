//
//  linked_list_test.c
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#include "tests.h"
#include "../linked_list/linked_list.c"

static void create_Node_test() {
    
    struct node *pHead = createNode(0);
    struct node *a = createNode(5);
    struct node *b = createNode(10);
    struct node *c = createNode(15);
    
    assert_null	(pHead->pLink);
    assert_int_equal(pHead->data, 0);
    assert_null	(a->pLink);
    assert_int_equal(a->data, 5);
    assert_null	(b->pLink);
    assert_int_equal(b->data, 10);
    assert_null	(c->pLink);
    assert_int_equal(c->data, 15);
}

static void add_node_test() {
    //assert_int_equal(count_list(pHead), 4);
}

static void delete_node_test() {
    //delete_node();
    
}

static void edit_node_test() {
    //edit_node();
}

static void move_node_test() {
    //move_node();
}

static void display_list_test() {
    //display_list();
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(create_Node_test),
        cmocka_unit_test(add_node_test),
        cmocka_unit_test(delete_node_test),
        cmocka_unit_test(edit_node_test),
        cmocka_unit_test(move_node_test),
        cmocka_unit_test(display_list_test),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
