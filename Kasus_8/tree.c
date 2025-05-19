#include <stdio.h>
#include "tree.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    infotype info;
    address fs, nb, pr;
    
    // Initialize all nodes to default values
    for (i = 0; i <= jml_maks; i++) {
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
    
    // Input nodes in level order
    printf("\nInput %d nodes in level order:\n", Jml_Node);
    printf("- Use indices (1-%d) for node positions\n", Jml_Node);
    printf("- Enter 0 for nil values (no son/brother/parent)\n\n");
    
    for (i = 1; i <= Jml_Node; i++) {
        printf("Node %d:\n", i);
        
        printf("Info (character): ");
        scanf(" %c", &info);
        
        do {
            printf("First Son index (0 if none, max %d): ", Jml_Node);
            scanf("%d", &fs);
            if (fs < 0 || fs > Jml_Node)
                printf("Invalid index! Please enter 0-%d\n", Jml_Node);
        } while (fs < 0 || fs > Jml_Node);
        
        do {
            printf("Next Brother index (0 if none, max %d): ", Jml_Node);
            scanf("%d", &nb);
            if (nb < 0 || nb > Jml_Node)
                printf("Invalid index! Please enter 0-%d\n", Jml_Node);
        } while (nb < 0 || nb > Jml_Node);
        
        do {
            printf("Parent index (0 if root, max %d): ", Jml_Node);
            scanf("%d", &pr);
            if (pr < 0 || pr > Jml_Node)
                printf("Invalid index! Please enter 0-%d\n", Jml_Node);
        } while (pr < 0 || pr > Jml_Node);
        
        // Assign values to node
        X[i].info = info;
        X[i].ps_fs = fs;
        X[i].ps_nb = nb;
        X[i].ps_pr = pr;
        
        printf("\n");
    }
}

boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == '\0');
}

void PreOrderTraversal(Isi_Tree P, address root) {
    if (root != nil) {
        // Process parent
        printf("%c ", P[root].info);
        
        // Process first son
        PreOrderTraversal(P, P[root].ps_fs);
        
        // Process next brother
        PreOrderTraversal(P, P[root].ps_nb);
    }
}

void PreOrder(Isi_Tree P) {
    printf("PreOrder Traversal: ");
    PreOrderTraversal(P, 1); // Start from root (index 1)
    printf("\n");
}

void InOrderTraversal(Isi_Tree P, address root) {
    if (root != nil) {
        // Process first son
        InOrderTraversal(P, P[root].ps_fs);
        
        // Process parent
        printf("%c ", P[root].info);
        
        // Process remaining siblings by following next brother links
        address sibling = P[root].ps_fs;
        while (sibling != nil) {
            sibling = P[sibling].ps_nb;
            if (sibling != nil) {
                InOrderTraversal(P, sibling);
            }
        }
    }
}

void InOrder(Isi_Tree P) {
    printf("InOrder Traversal: ");
    InOrderTraversal(P, 1); // Start from root (index 1)
    printf("\n");
}

void PostOrderTraversal(Isi_Tree P, address root) {
    if (root != nil) {
        // Process first son
        PostOrderTraversal(P, P[root].ps_fs);
        
        // Process next brother
        PostOrderTraversal(P, P[root].ps_nb);
        
        // Process parent
        printf("%c ", P[root].info);
    }
}

void PostOrder(Isi_Tree P) {
    printf("PostOrder Traversal: ");
    PostOrderTraversal(P, 1); // Start from root (index 1)
    printf("\n");
}

void Level_order(Isi_Tree X, int Maks_node) {
    int queue[jml_maks];
    int front = 0, rear = 0;
    int current;
    
    printf("Level Order Traversal: ");
    
    if (IsEmpty(X)) {
        printf("Tree is empty\n");
        return;
    }
    
    // Enqueue root
    queue[rear++] = 1;
    
    while (front < rear) {
        // Dequeue
        current = queue[front++];
        
        // Process current node
        printf("%c ", X[current].info);
        
        // Find all children of the current node using first son and next brother links
        int child = X[current].ps_fs;
        
        while (child != nil) {
            // Enqueue child
            queue[rear++] = child;
            
            // Move to next brother
            child = X[child].ps_nb;
        }
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
    int i;
    printf("Tree Structure:\n");
    printf("Index | Info | First Son | Next Brother | Parent\n");
    printf("------|------|-----------|--------------|-------\n");
    
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            printf("%5d | %4c | %9d | %12d | %6d\n", 
                   i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
        }
    }
}

boolean Search(Isi_Tree P, infotype X) {
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            return true;
        }
    }
    return false;
}

int CountNodes(Isi_Tree P, address root) {
    if (root == nil) {
        return 0;
    }
    
    // Count this node, its first son, and next brother
    return 1 + CountNodes(P, P[root].ps_fs) + CountNodes(P, P[root].ps_nb);
}

int nbElmt(Isi_Tree P) {
    return CountNodes(P, 1); // Start from root (index 1)
}

boolean IsLeaf(Isi_Tree P, address node) {
    return (P[node].ps_fs == nil);
}

int CountLeaves(Isi_Tree P, address root) {
    if (root == nil) {
        return 0;
    }
    
    if (IsLeaf(P, root)) {
        return 1 + CountLeaves(P, P[root].ps_nb);
    } else {
        return CountLeaves(P, P[root].ps_fs) + CountLeaves(P, P[root].ps_nb);
    }
}

int nbDaun(Isi_Tree P) {
    return CountLeaves(P, 1); // Start from root (index 1)
}

int FindLevel(Isi_Tree P, address root, infotype X, int currentLevel) {
    if (root == nil) {
        return -1; // Node not found
    }
    
    if (P[root].info == X) {
        return currentLevel;
    }
    
    // Check first son
    int level = FindLevel(P, P[root].ps_fs, X, currentLevel + 1);
    if (level != -1) {
        return level;
    }
    
    // Check next brother at the same level
    return FindLevel(P, P[root].ps_nb, X, currentLevel);
}

int Level(Isi_Tree P, infotype X) {
    return FindLevel(P, 1, X, 0); // Start from root (index 1) at level 0
}

int FindDepth(Isi_Tree P, address root) {
    if (root == nil) {
        return -1; // Empty subtree has depth -1
    }
    
    // Calculate depth of first son and next brother
    int depthFirstSon = FindDepth(P, P[root].ps_fs) + 1;
    int depthNextBrother = FindDepth(P, P[root].ps_nb);
    
    // Return the maximum depth
    return Max(depthFirstSon, depthNextBrother);
}

int Depth(Isi_Tree P) {
    return FindDepth(P, 1); // Start from root (index 1)
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
} 