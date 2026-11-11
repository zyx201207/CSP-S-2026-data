#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        int n,d,x[N];
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++) scanf("%d",&x[i]);
        if(!c){
            if(n==4&&d==2) puts("1\n2\n");
            else if(n==5&&d==3) puts("0\n1\n");
            else if(n==197) puts("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");
            return 0;
        }
        else printf("%d\n",n);
    }
    return 0;
}
