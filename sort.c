#include <stdio.h>

int main() {
    int tab[] = {3, 4, 1, 5, 2};
    int n = 5;
    int x;

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if(tab[j] > tab[j+1]) {
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp; 

            }
        }
    }

    for(int i=0; i<5; i++) {
        printf("%d ", tab[i]);
    }

    int a = 0;
    int b = 10;

    int c = a / b;

    return 0;
}