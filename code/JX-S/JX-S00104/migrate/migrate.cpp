#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e6+10;
int c,T;
int n,d;
int x[maxn];
int ans=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++){
            scanf("%d",&x[i]);
        }
        while(true){
            d-=x[i+1]-x[i];
            if(d<=0) {
                ans++;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
