#include <stdio.h>
#include <stdlib.h>

int add(int x) {
    int static sum = 0;
    sum += x;
    return sum;
}

int main () {

    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",add(5));
    printf("%d\n",sum);



    return 0;
}
