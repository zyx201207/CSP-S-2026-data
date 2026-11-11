#include <bits/stdc++.h>
using namespace std;
int c,t,n,m;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&m);
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        if(m>=a[n]-a[1]){
            printf("0\n");
        }
    }
    return 0;
}
