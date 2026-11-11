#include <bits/stdc++.h>
using namespace std;
mt19937 rnd((random_device())());

int main() {
    freopen("data.in","w",stdout);
    int T=rnd()%100+1;
    printf("0 %d\n",T);
    while(T--) {
        int n=rnd()%20+2,m=rnd()%(n-1)+2;
        printf("%d %d\n",n,m);
        for(int i=2;i<=n;i++) printf("%d %d\n",rnd()%(i-1)+1,i);printf("\n");
    }
    return 0;
}
