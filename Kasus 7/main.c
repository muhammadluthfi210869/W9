#include "nbtrees.h"

void create_sample_tree(Isi_Tree tree) {
    Create_tree(tree, 10);
    
    tree[1].info = 'A';
    tree[1].ps_fs = 2;
    tree[1].ps_nb = nil;
    tree[1].ps_pr = nil;
    
    tree[2].info = 'B';
    tree[2].ps_fs = 5;
    tree[2].ps_nb = 3;
    tree[2].ps_pr = 1;
    
    tree[3].info = 'C';
    tree[3].ps_fs = 7;
    tree[3].ps_nb = 4;
    tree[3].ps_pr = 1;
    
    tree[4].info = 'D';
    tree[4].ps_fs = 8;
    tree[4].ps_nb = nil;
    tree[4].ps_pr = 1;
    
    tree[5].info = 'E';
    tree[5].ps_fs = nil;
    tree[5].ps_nb = 6;
    tree[5].ps_pr = 2;
    
    tree[6].info = 'F';
    tree[6].ps_fs = nil;
    tree[6].ps_nb = nil;
    tree[6].ps_pr = 2;
    
    tree[7].info = 'G';
    tree[7].ps_fs = nil;
    tree[7].ps_nb = nil;
    tree[7].ps_pr = 3;
    
    tree[8].info = 'H';
    tree[8].ps_fs = nil;
    tree[8].ps_nb = 9;
    tree[8].ps_pr = 4;
    
    tree[9].info = 'I';
    tree[9].ps_fs = nil;
    tree[9].ps_nb = 10;
    tree[9].ps_pr = 4;
    
    tree[10].info = 'J';
    tree[10].ps_fs = nil;
    tree[10].ps_nb = nil;
    tree[10].ps_pr = 4;
}

void display_menu() {
    printf("\n=== Non-Binary Tree Operations ===\n");
    printf("1. Display Tree Structure\n");
    printf("2. PreOrder Traversal\n");
    printf("3. InOrder Traversal\n");
    printf("4. PostOrder Traversal\n");
    printf("5. Level Order Traversal\n");
    printf("6. Search Node\n");
    printf("7. Count Total Nodes\n");
    printf("8. Count Leaf Nodes\n");
    printf("9. Find Node Level\n");
    printf("10. Find Tree Depth\n");
    printf("11. Compare Two Nodes\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Isi_Tree tree;
    int choice;
    char search_char;
    int num_nodes = 10;
    
    create_sample_tree(tree);
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: PrintTree(tree); break;
            case 2: printf("\nPreOrder Traversal: "); PreOrder(tree); printf("\n"); break;
            case 3: printf("\nInOrder Traversal: "); InOrder(tree); printf("\n"); break;
            case 4: printf("\nPostOrder Traversal: "); PostOrder(tree); printf("\n"); break;
            case 5: printf("\nLevel Order Traversal: "); Level_order(tree, num_nodes); printf("\n"); break;
            case 6:
                printf("\nEnter character to search: ");
                scanf(" %c", &search_char);
                printf("Node '%c' %s in the tree\n", search_char, Search(tree, search_char) ? "found" : "not found");
                break;
            case 7: printf("\nTotal number of nodes: %d\n", nbElmt(tree)); break;
            case 8: printf("\nNumber of leaf nodes: %d\n", nbDaun(tree)); break;
            case 9:
                printf("\nEnter character to find its level: ");
                scanf(" %c", &search_char);
                int level = Level(tree, search_char);
                printf(level != -1 ? "Level of node '%c': %d\n" : "Node '%c' not found in the tree\n", search_char, level);
                break;
            case 10: printf("\nTree depth: %d\n", Depth(tree)); break;
            case 11:
                printf("\nEnter two characters to compare: ");
                char c1, c2;
                scanf(" %c %c", &c1, &c2);
                printf("Maximum character: %c\n", Max(c1, c2));
                break;
            case 12: printf("\nExiting program...\n"); return 0;
            default: printf("\nInvalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
} 