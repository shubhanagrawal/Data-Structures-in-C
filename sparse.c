#include<stdio.h>

// Accept matrix elements
void accept(int a[20][20], int m, int n) {
    printf("\nEnter Elements of the Matrix\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Enter Element (%d %d): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

// Display matrix elements
void display(int a[20][20], int m, int n) {
    printf("\nThe Elements of The Matrix are\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Convert matrix to sparse matrix format
void sparse(int a[20][20], int m, int n, int b[100][3]) {
    int count = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] != 0) {
                b[count][0] = i;
                b[count][1] = j;
                b[count][2] = a[i][j];
                count++;
            }
        }
    }
    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = count - 1;
}

// Display sparse matrix
void displaySparse(int b[100][3]) {
    printf("\nSparse Matrix Representation:\n");
    printf("Row\tColumn\tValue\n");
    for(int i = 0; i <= b[0][2]; i++) {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

// Simple transpose of sparse matrix
void simpletranspose(int b[100][3], int d[100][3]) {
    int n1 = b[0][2];
    d[0][0] = b[0][1]; // New number of rows
    d[0][1] = b[0][0]; // New number of columns
    d[0][2] = n1;

    int k = 1;
    for(int i = 0; i < b[0][1]; i++) {
        for(int j = 1; j <= n1; j++) {
            if(i == b[j][1]) {
                d[k][0] = b[j][1];
                d[k][1] = b[j][0];
                d[k][2] = b[j][2];
                k++;
            }
        }
    }
}

void fasttranspose(int b[100][3],int e[100][3])
{
    int i,m,n;
    int pos[50]={0};
    int count[50]={0};
    for(i=1;i<=b[0][2];i++)
    {
        m=b[i][1];
        count[m]++;
    }
    pos[0]=1;
    for(i=1;i<b[0][1];i++)
    {
        pos[i]=pos[i-1]+count[i-1];
    }
    for(i=1;i<=b[0][2];i++)
    {
        m=b[i][1];
        n=pos[m];
        pos[m]++;
        e[n][0]=b[i][1];
        e[n][1]=b[i][0];
        e[n][2]=b[i][2];
    }
    e[0][0]=b[0][0];
    e[0][1]=b[0][1];
    e[0][2]=b[0][2];
}

// Main function
int main() {
    int a[20][20], b[100][3], d[100][3],e[100][3];
    int m, n;

    printf("Enter Rows and Columns: ");
    scanf("%d %d", &m, &n);

    accept(a, m, n);
    display(a, m, n);

    sparse(a, m, n, b);
    displaySparse(b);

    simpletranspose(b, d);

    printf("\nTranspose of Sparse Matrix:\n");
    displaySparse(d);

    fasttranspose(b,e);

    printf("\nFast Transpose of Sparse Matrix:\n");
    displaySparse(e);


    return 0;
}
