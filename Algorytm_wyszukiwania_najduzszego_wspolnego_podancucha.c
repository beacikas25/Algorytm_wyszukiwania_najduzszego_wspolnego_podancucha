#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCS(char *A, char *B, int n, int m) {
    int C[n+1][m+1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                C[i][j] = 0;
            } else if (A[i-1] == B[j-1]) {
                C[i][j] = C[i-1][j-1] + 1;
            } else {
                C[i][j] = max(C[i-1][j], C[i][j-1]);
            }
        }
    }
    return C[n][m];
}

int main() {
    char A[] = "Beata";
    char B[] = "Beataeae";
    int n = strlen(A);
    int m = strlen(B);
    printf("Algorytm wyszukiwania najdluzszego wspolnego podlancucha: %d\n", LCS(A, B, n, m));
    return 0;
}
