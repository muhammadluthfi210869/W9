#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void display_menu() {
    printf("\n1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 node Tree\n");
    printf("11. Exit\n");
    printf("Pilih Menu: ");
}

void create_sample_tree(Isi_Tree tree, int num_nodes) {
    int i;
    
    // Initialize tree
    for (i = 0; i <= jml_maks; i++) {
        tree[i].info = '\0';
        tree[i].ps_fs = nil;
        tree[i].ps_nb = nil;
        tree[i].ps_pr = nil;
    }
    
    // Create a sample tree
    // Using numeric values for this example
    // Node 1: 4 (root)
    tree[1].info = '4';
    tree[1].ps_fs = 2;  // First son is 1
    tree[1].ps_nb = 0;  // No next brother
    tree[1].ps_pr = 0;  // No parent (it's the root)
    
    // Node 2: 1
    tree[2].info = '1';
    tree[2].ps_fs = 4;  // First son is 3
    tree[2].ps_nb = 3;  // Next brother is 2
    tree[2].ps_pr = 1;  // Parent is 4
    
    // Node 3: 2
    tree[3].info = '2';
    tree[3].ps_fs = 0;  // No first son
    tree[3].ps_nb = 0;  // No next brother
    tree[3].ps_pr = 1;  // Parent is 4
    
    // Node 4: 3
    tree[4].info = '3';
    tree[4].ps_fs = 0;  // No first son
    tree[4].ps_nb = 0;  // No next brother
    tree[4].ps_pr = 2;  // Parent is 1
    
    // Node 5: 5
    tree[5].info = '5';
    tree[5].ps_fs = 0;  // No first son
    tree[5].ps_nb = 0;  // No next brother
    tree[5].ps_pr = 2;  // Parent is 1
}

void display_tree_visualization(Isi_Tree tree, int node_index, int level) {
    if (node_index == nil) {
        return;
    }
    
    // Print current node with indentation based on level
    int i;
    for (i = 0; i < level; i++) {
        printf("    ");
    }
    
    if (level > 0) {
        printf("|-- ");
    }
    
    printf("%c\n", tree[node_index].info);
    
    // Process first son (with increased indentation level)
    display_tree_visualization(tree, tree[node_index].ps_fs, level + 1);
    
    // Process next brother (with same indentation level)
    display_tree_visualization(tree, tree[node_index].ps_nb, level);
}

void print_tree_visualization(Isi_Tree tree) {
    printf("\nVisualisasi Tree:\n");
    printf("----------------\n");
    display_tree_visualization(tree, 1, 0); // Start from root (index 1) at level 0
    printf("----------------\n");
}

void print_node_details(Isi_Tree tree, int num_nodes) {
    int i;
    
    // First display tree visualization
    print_tree_visualization(tree);
    
    printf("\nSeluruh Node pada Non Binary Tree:\n");
    
    for (i = 1; i <= num_nodes; i++) {
        printf("\n---> Indeks ke-%d\n", i);
        printf("-----------------------------\n");
        printf("info array ke %d\t: %c\n", i, tree[i].info);
        printf("first son array ke %d\t: %d\n", i, tree[i].ps_fs);
        printf("next brother array ke %d\t: %d\n", i, tree[i].ps_nb);
        printf("parent array ke %d\t: %d\n", i, tree[i].ps_pr);
        printf("-----------------------------\n");
    }
    
    printf("\nKlik apapun untuk melanjutkan");
    getchar(); // Consume newline
    getchar(); // Wait for input
}

void compare_nodes(Isi_Tree tree, int num_nodes) {
    int node1, node2;
    
    printf("\nMasukkan indeks node pertama (1-%d): ", num_nodes);
    scanf("%d", &node1);
    
    if (node1 < 1 || node1 > num_nodes || tree[node1].info == '\0') {
        printf("Node tidak valid!\n");
        return;
    }
    
    printf("Masukkan indeks node kedua (1-%d): ", num_nodes);
    scanf("%d", &node2);
    
    if (node2 < 1 || node2 > num_nodes || tree[node2].info == '\0') {
        printf("Node tidak valid!\n");
        return;
    }
    
    printf("\nPerbandingan Node %d dan Node %d:\n", node1, node2);
    printf("-----------------------------\n");
    printf("Node %d info: %c\n", node1, tree[node1].info);
    printf("Node %d info: %c\n", node2, tree[node2].info);
    
    printf("\nNode %d level: %d\n", node1, Level(tree, tree[node1].info));
    printf("Node %d level: %d\n", node2, Level(tree, tree[node2].info));
    
    if (tree[node1].ps_pr == tree[node2].ps_pr && tree[node1].ps_pr != 0) {
        printf("\nNode %d dan Node %d adalah saudara (memiliki parent yang sama)\n", 
               node1, node2);
    } else {
        printf("\nNode %d dan Node %d bukan saudara\n", node1, node2);
    }
    
    if (tree[node2].ps_pr == node1) {
        printf("Node %d adalah parent dari Node %d\n", node1, node2);
    } else if (tree[node1].ps_pr == node2) {
        printf("Node %d adalah parent dari Node %d\n", node2, node1);
    }
}

int main() {
    Isi_Tree tree;
    int choice = 0;
    int num_nodes = 5;
    char node_info;
    
    // Create sample tree matching the image
    create_sample_tree(tree, num_nodes);
    
    while (choice != 11) {
        system("cls"); // Clear screen (for Windows)
        // For Unix/Linux use: system("clear");
        
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nTraversal PreOrder: ");
                PreOrder(tree);
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
                break;
                
            case 2:
                printf("\nTraversal InOrder: ");
                InOrder(tree);
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
                break;
                
            case 3:
                printf("\nTraversal PostOrder: ");
                PostOrder(tree);
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
                break;
                
            case 4:
                printf("\nTraversal Level Order: ");
                Level_order(tree, num_nodes);
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
                break;
                
            case 5:
                print_node_details(tree, num_nodes);
                break;
                
            case 6:
                printf("\nMasukkan karakter yang ingin dicari: ");
                getchar(); // Consume newline
                scanf("%c", &node_info);
                
                if (Search(tree, node_info)) {
                    printf("\nNode '%c' ditemukan pada tree\n", node_info);
                    printf("Level dari node '%c': %d\n", node_info, Level(tree, node_info));
                } else {
                    printf("\nNode '%c' tidak ditemukan pada tree\n", node_info);
                }
                
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
                break;
                
            case 7:
                printf("\nJumlah daun (leaf): %d\n", nbDaun(tree));
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
                break;
                
            case 8:
                printf("\nMasukkan karakter yang ingin dicari levelnya: ");
                getchar(); // Consume newline
                scanf("%c", &node_info);
                
                if (Search(tree, node_info)) {
                    printf("\nLevel dari node '%c': %d\n", node_info, Level(tree, node_info));
                } else {
                    printf("\nNode '%c' tidak ditemukan pada tree\n", node_info);
                }
                
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
                break;
                
            case 9:
                printf("\nKedalaman Tree: %d\n", Depth(tree));
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
                break;
                
            case 10:
                compare_nodes(tree, num_nodes);
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
                break;
                
            case 11:
                printf("\nProgram selesai.\n");
                break;
                
            default:
                printf("\nPilihan tidak valid. Silakan pilih 1-11.\n");
                printf("\nKlik apapun untuk melanjutkan");
                getchar(); // Consume newline
                getchar(); // Wait for input
        }
    }
    
    return 0;
} 