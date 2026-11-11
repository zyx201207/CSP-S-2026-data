#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    ll n,d;
    while(t--){
        scanf("%lld%lld",&n,&d);
        ll x[n];
        int cnt=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&x[i]);
            if(i>=2&&x[i]-x[i-1]<=d){
                cnt++;
            }
        }
       ll ma=cnt*(cnt-1)/2;
       int f;
       int ans=0;
        for(int i=1;i<=ma;i++){
            f=(clock()*10000)<<123%100;
            if(f<=25){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
