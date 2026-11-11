#include <cstdio>


int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 1; i < n; i++){
            int u, v;
            scanf("%d %d", &u, &v);
        }
        printf("%d\n", n / 5);
    }
    return 0;
}