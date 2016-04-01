//
//  linked_list_test.c
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#include "tests.h"
#include "../linked_list/linked_list.h"

struct Node *pHead;

static void linked_list_create_test() {
    pHead = linked_list_create();

    assert_null	(pHead->pNext);
    assert_int_equal(pHead->data, 0);
    assert_int_equal(linked_list_count(pHead), 1);
}

static void linked_list_add_test() {
    linked_list_create_test();
    
    linked_list_add(pHead, 5);
    linked_list_add(pHead, 10);
    linked_list_add(pHead, 15);
    
    assert_int_equal(pHead->pNext->data, 5);
    assert_int_equal(pHead->pNext->pNext->data, 10);
    assert_int_equal(pHead->pNext->pNext->pNext->data, 15);
    assert_null(pHead->pNext->pNext->pNext->pNext);
    assert_int_equal(linked_list_count(pHead), 4);
}

static void linked_list_delete_test() {
    linked_list_add_test();
    
    linked_list_delete(pHead, 2);
    assert_int_equal(pHead->pNext->data, 5);
    assert_int_equal(pHead->pNext->pNext->data, 15);
    assert_null(pHead->pNext->pNext->pNext);
    assert_int_equal(linked_list_count(pHead), 3);
}

static void linked_list_delete_head_test() {
    linked_list_add_test();
    
    linked_list_delete(pHead, 0);
    assert_int_equal(pHead->data, 0);
    assert_int_equal(linked_list_count(pHead), 4);
}

static void linked_list_delete_none_existant_test() {
    linked_list_add_test();
    
    linked_list_delete(pHead, 10);
    assert_int_equal(linked_list_count(pHead), 4);
}

static void move_node_test() {
    //move_node();
}

static void display_list_test() {
    //display_list();
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(linked_list_create_test),
        cmocka_unit_test(linked_list_add_test),
        cmocka_unit_test(linked_list_delete_test),
        cmocka_unit_test(linked_list_delete_head_test),
        cmocka_unit_test(linked_list_delete_none_existant_test),
        cmocka_unit_test(move_node_test),
        cmocka_unit_test(display_list_test),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
