#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        char u[22];
        scanf("%s",&u);
        printf("%s\n",u);
    }

    return 0;
}