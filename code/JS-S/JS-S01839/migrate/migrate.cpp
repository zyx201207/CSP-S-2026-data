#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define st string
#define db double
#define ch char
#define bo bool
#define s2 505
#define s3 5005
#define s4 50005
#define s5 300005
#define s6 1000005
#define s7 10000005
using namespace std;
int c,t,n,d,a[s5],ans=0;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            int x=lower_bound(a+1,a+1+n,d+1+a[i])-a;
            int y=lower_bound(a+1,a+1+n,d*2-1+a[i])-a;
            if(x-i!=2) continue;
            if(x==n+1) continue;
            if(y==n+1){
                ans+=n-x+1;
                continue;
            }
            ans+=y-x+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
