#include <stdio.h>
#include <string.h>

int main () {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    char s[n][20], t[n][20];
    for (int i = 0; i < n; i++){
        scanf("%s %s, s[i], t[i]");
    }

    char temp[n][20];
    for(int i = 0; i < m; i++) {
        strcpy(temp[i], t[i]);
    }

    char ticket[k][20];;
    int x = 0;
    for (int i = 0; i < n; i++){
        if (x < k){
            for (int j = 0; j < m; j++){
                if (!strcmp(t[i], temp[j])){
                    break;
                } else if (j + 1 == m){
                    strcpy(temp[j+1], t[i]);
                    m++;
                    strcpy(ticket[x++], s[i]);
                }
            }
        }
    }

    printf("%d\n", x);
    if (x) {
        for(int  i = 0; i < x; i++){
            printf("%s\n, ticket[i]");
        }
    }

    return 0;
}
