//
//  linked_list_test.c
//  
//
//  Created by Krishan Solanki on 25/03/2016.
//
//

#include "tests.h"
#include "../linked_list/linked_list.h"

static struct Node pHead;

static int
setup(void **state) {
    (void) state;
    
    pHead = linked_list_init();
    
    return 0;
}

static int
teardown(void **state) {
    (void) state;
    
    linked_list_destroy(&pHead);
    
    return 0;
}

static void
_linked_list_create_test();

static void
_linked_list_add_test();

static void
_linked_list_delete_test();

static void
_linked_list_delete_head_test();

static void
_linked_list_delete_none_existant_test();

static void
_move_node_test();

static void
_display_list_test();



int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup_teardown(_linked_list_create_test, setup, teardown),
        cmocka_unit_test_setup_teardown(_linked_list_add_test, setup, teardown),
        cmocka_unit_test_setup_teardown(_linked_list_delete_test, setup, teardown),
        cmocka_unit_test_setup_teardown(_linked_list_delete_head_test, setup, teardown),
        cmocka_unit_test_setup_teardown(_linked_list_delete_none_existant_test, setup, teardown),
        cmocka_unit_test_setup_teardown(_move_node_test, setup, teardown),
        cmocka_unit_test_setup_teardown(_display_list_test, setup, teardown),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}

static void
_linked_list_create_test() {
    assert_null	(pHead.pNext);
    assert_int_equal(pHead.data, 0);
    assert_int_equal(linked_list_count(&pHead), 1);
}

static void
_linked_list_add_test() {
    linked_list_add(&pHead, 5);
    linked_list_add(&pHead, 10);
    linked_list_add(&pHead, 15);
    
    assert_int_equal(pHead.pNext->data, 5);
    assert_int_equal(pHead.pNext->pNext->data, 10);
    assert_int_equal(pHead.pNext->pNext->pNext->data, 15);
    assert_null(pHead.pNext->pNext->pNext->pNext);
    assert_int_equal(linked_list_count(&pHead), 4);
}

static void
_linked_list_delete_test() {
    _linked_list_add_test();
    
    linked_list_delete(&pHead, 2);
    assert_int_equal(pHead.pNext->data, 5);
    assert_int_equal(pHead.pNext->pNext->data, 15);
    assert_null(pHead.pNext->pNext->pNext);
    assert_int_equal(linked_list_count(&pHead), 3);
}

static void
_linked_list_delete_head_test() {
    _linked_list_add_test();
    
    linked_list_delete(&pHead, 0);
    assert_int_equal(pHead.data, 0);
    assert_int_equal(linked_list_count(&pHead), 4);
}

static void
_linked_list_delete_none_existant_test() {
    _linked_list_add_test();
    
    linked_list_delete(&pHead, 10);
    assert_int_equal(linked_list_count(&pHead), 4);
}

static void
_move_node_test() {
    //move_node();
}

static void
_display_list_test() {
    //display_list();
}
