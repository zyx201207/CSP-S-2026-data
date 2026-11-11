#include <bits/stdc++.h>
using namespace std;
mt19937 rnd((random_device())());

int main() {
    freopen("hub.in","w",stdout);
    int T=2;
    printf("0 %d\n",T);
    while(T--) {
        int n=1e6,m=rnd()%(n-1)+2;
        printf("%d %d\n",n,m);
        for(int i=2;i<=n;i++) printf("%d %d\n",i-rnd()%min(i-1,4)-1,i);printf("\n");
    }
    return 0;
}
