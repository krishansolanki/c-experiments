//
//  linked_list_test.c
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#include "tests.h"
#include "../linked_list/linked_list.c"

struct node *pHead;

static void create_node_test() {
    pHead = createHeadNode();

    assert_null	(pHead->pNext);
    assert_int_equal(pHead->data, 0);
    assert_int_equal(count(pHead), 1);
}

static void add_node_test() {
    create_node_test();
    
    addNodeToList(pHead, 5);
    addNodeToList(pHead, 10);
    addNodeToList(pHead, 15);
    
    assert_int_equal(pHead->pNext->data, 5);
    assert_int_equal(pHead->pNext->pNext->data, 10);
    assert_int_equal(pHead->pNext->pNext->pNext->data, 15);
    assert_null(pHead->pNext->pNext->pNext->pNext);
    assert_int_equal(count(pHead), 4);
}

static void delete_node_test() {
    add_node_test();
    
    deleteNode(pHead, 2);
    assert_int_equal(pHead->pNext->data, 5);
    assert_int_equal(pHead->pNext->pNext->data, 15);
    assert_null(pHead->pNext->pNext->pNext);
    assert_int_equal(count(pHead), 3);
}

static void delete_head_node_test() {
    add_node_test();
    
    deleteNode(pHead, 0);
    assert_int_equal(pHead->data, 0);
    assert_int_equal(count(pHead), 4);
}

static void delete_none_existant_node_test() {
    add_node_test();
    
    deleteNode(pHead, 10);
    assert_int_equal(count(pHead), 4);
}

static void move_node_test() {
    //move_node();
}

static void display_list_test() {
    //display_list();
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(create_node_test),
        cmocka_unit_test(add_node_test),
        cmocka_unit_test(delete_node_test),
        cmocka_unit_test(delete_head_node_test),
        cmocka_unit_test(delete_none_existant_node_test),
        cmocka_unit_test(move_node_test),
        cmocka_unit_test(display_list_test),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
