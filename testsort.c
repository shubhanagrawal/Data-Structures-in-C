#include <stdio.h>
#include <string.h>

struct student {
    int rno;
    char name[20];
};

void accept(struct student s[], int n) {
    printf("Enter Roll no and Name of students:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i].rno);
        scanf("%s", s[i].name);
    }
}

void display(struct student s[], int n) {
    printf("\nThe Roll no and Name of Students are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\n", s[i].rno, s[i].name);
    }
}

void bubble(struct student s[], int n) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].rno > s[j + 1].rno) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void selection(struct student s[], int n) {
    int minpos;
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        minpos = i;
        for (int j = i + 1; j < n; j++) {
            if (s[minpos].rno > s[j].rno) {
                minpos = j;
            }
        }
        if (minpos != i) {
            temp = s[minpos];
            s[minpos] = s[i];
            s[i] = temp;
        }
    }
}void insertion(struct student s[],int n)
{
	struct student temp;
    int j,key;
	for(int i=1;i<n;i++)
	{
        key=s[i].rno;
        j=i-1;
        while(s[j].rno>key&&j>=0)
        {
            s[j+1].rno=s[j].rno;
            j=j-1;

        }
        s[j+1].rno=key;
    }
}
void shellsort(struct student s[], int n) {
    int gap = n / 2;
    struct student temp;
    int swapped;
    do {
        do {
         swapped = 0;
            for (int i = 0; i < n - gap; i++) {
                if (s[i].rno > s[i + gap].rno) {
                    temp = s[i];
                    s[i] = s[i + gap];
                    s[i + gap] = temp;
                    swapped = 1;
                }
            }
        } while (swapped == 1);
    } while ((gap = gap / 2) >= 1);
}


int main() {
    struct student s[20];
    int ch, n;

    printf("Enter choice (1 for Bubble Sort, 2 for Selection Sort, 3 for Insertion Sort , 4 for Shell Sort): ");
    scanf("%d", &ch);

    printf("Enter number of students: ");
    scanf("%d", &n);

    switch (ch) {
        case 1:
            accept(s, n);
            display(s, n);
            bubble(s, n);
            printf("The Name and Roll nos after Bubble Sort are:\n");
            display(s, n);
            break;

        case 2:
            accept(s, n);
            display(s, n);
            selection(s, n);
            printf("The Name and Roll nos after Selection Sort are:\n");
            display(s, n);
            break;
        case 3 :
         
        accept(s,n);
        display(s,n);
        selection(s,n);
        printf("The Name and Roll no after Insertion Sort are :\n");
        display(s,n);
        break;

        case 4:
        accept(s,n);
        display(s,n);
        shellsort(s,n);
        printf("The Name and Roll no after Insertion Sort are :\n");
        display(s,n);
        break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
