#include "nbtrees.h"

//go a
void Create_tree(Isi_Tree X, int Jml_node) {
    int i;
    for (i = 0; i <= jml_maks; i++) {
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
}

bool IsEmpty(Isi_Tree P) {
    return (P[1].info == '\0');
}

void PreOrder(Isi_Tree P) {
    if (P[1].info != '\0') {
        printf("%c ", P[1].info);
        if (P[1].ps_fs != nil) {
            Isi_Tree temp;
            int i;
            for (i = 1; i <= jml_maks; i++) {
                temp[i] = P[i];
            }
            temp[1] = P[P[1].ps_fs];
            PreOrder(temp);
        }
        if (P[1].ps_nb != nil) {
            Isi_Tree temp;
            int i;
            for (i = 1; i <= jml_maks; i++) {
                temp[i] = P[i];
            }
            temp[1] = P[P[1].ps_nb];
            PreOrder(temp);
        }
    }
}

void InOrder(Isi_Tree P) {
    if (P[1].info != '\0') {
        if (P[1].ps_fs != nil) {
            Isi_Tree temp;
            int i;
            for (i = 1; i <= jml_maks; i++) {
                temp[i] = P[i];
            }
            temp[1] = P[P[1].ps_fs];
            InOrder(temp);
        }
        printf("%c ", P[1].info);
        if (P[1].ps_nb != nil) {
            Isi_Tree temp;
            int i;
            for (i = 1; i <= jml_maks; i++) {
                temp[i] = P[i];
            }
            temp[1] = P[P[1].ps_nb];
            InOrder(temp);
        }
    }
}

void PostOrder(Isi_Tree P) {
    if (P[1].info != '\0') {
        if (P[1].ps_fs != nil) {
            Isi_Tree temp;
            int i;
            for (i = 1; i <= jml_maks; i++) {
                temp[i] = P[i];
            }
            temp[1] = P[P[1].ps_fs];
            PostOrder(temp);
        }
        if (P[1].ps_nb != nil) {
            Isi_Tree temp;
            int i;
            for (i = 1; i <= jml_maks; i++) {
                temp[i] = P[i];
            }
            temp[1] = P[P[1].ps_nb];
            PostOrder(temp);
        }
        printf("%c ", P[1].info);
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    int i;
    for (i = 1; i <= Maks_node; i++) {
        if (X[i].info != '\0') {
            printf("%c ", X[i].info);
        }
    }
}

void PrintTree(Isi_Tree P) {
    int i;
    printf("\nTree Structure:\n");
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            printf("Node %d: %c\n", i, P[i].info);
            printf("  Parent: %d\n", P[i].ps_pr);
            printf("  First Son: %d\n", P[i].ps_fs);
            printf("  Next Brother: %d\n", P[i].ps_nb);
        }
    }
}

bool Search(Isi_Tree P, infotype X) {
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            return true;
        }
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            count++;
        }
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == nil) {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    int level = 0;
    int current = 1;
    
    while (current <= jml_maks) {
        if (P[current].info == X) {
            return level;
        }
        if (P[current].ps_fs != nil) {
            current = P[current].ps_fs;
            level++;
        } else if (P[current].ps_nb != nil) {
            current = P[current].ps_nb;
        } else {
            while (P[current].ps_nb == nil && P[current].ps_pr != nil) {
                current = P[current].ps_pr;
                level--;
            }
            if (P[current].ps_nb != nil) {
                current = P[current].ps_nb;
            } else {
                break;
            }
        }
    }
    return -1;
}

int Depth(Isi_Tree P) {
    int maxLevel = 0;
    int i;
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            int nodeLevel = Level(P, P[i].info);
            if (nodeLevel > maxLevel) {
                maxLevel = nodeLevel;
            }
        }
    }
    return maxLevel;
}

infotype Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
} 