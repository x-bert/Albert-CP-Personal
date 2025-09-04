#include <stdio.h>
#include <string.h>

int max(int susu, int tot, inttanda){
    int inx = 1;
    for(int i = 1; i <= tot; i++){
        if(!tanda[i] && (inx == -1 || susu[i] > susu[inx])){
            inx = i;
        }
    }

    return inx;
}

int main () {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    int tanggal = 0;
    int totS = 0;
    int susu[N+1];
    int tanda[N+1];

    memset(tanda, 0, sizeof(tanda));
    for(int i = 1; i <= N; i++){
        scanf("%d", &susu[i]);

        totS += susu[i];

        while(totS > M && K > 0){
            int inx = max(susu, i, tanda);
            if(inx != -1){
                tanda[inx] = 1;
                totS -= susu[inx];
                K--;
            } else {
                break;
            }
        }
        if (totS > M)
        break;
        tanggal++;
    }
    printf("%d\n", tanggal);
    return 0;
}
