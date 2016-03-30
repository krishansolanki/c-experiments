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
    
    struct node *pHead = createHeadNode();

    assert_null	(pHead->pLink);
    assert_int_equal(pHead->data, 0);

}

static void add_node_test() {
    struct node *pHead = createHeadNode();
    
    addNodeToList(pHead, 5);
    addNodeToList(pHead, 10);
    addNodeToList(pHead, 15);
    
    assert_int_equal(count(pHead), 4);
    //assert_ptr_equal(pHead.pLink, a);
    //assert_ptr_equal(a->pLink, b);
    //assert_ptr_equal(b->pLink, c);
    //assert_null(c->pLink);
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
