#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
int k[2000005];
int sum = 0,sumi = 0;
int n,d;
void dfs(int x,int y,int dep){
    if(x == y){
        if(dep < sum){
            sum = dep;
            sumi = 1;
        }
        else if(dep == sum) sumi++;
        return;
    }
    int l = 0;
    for(int i=x+1;i<=y;++i){
        l+=abs(a[i]-a[i-1]);
        if(l <= d) dfs(i,y,dep+1);
    }
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int fl = 1;
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            k[i] = a[i]-a[i-1];
        }
        for(int i=3;i<=n;++i){
            if(k[i] != k[i-1]) fl = 0;
        }
        int fl2 = 0;
        for(int i=1;i<=n;++i){
            int x = abs(a[i]-a[n]);
            int y = abs(a[i]-a[1]);
            if(x <= d &&y <= d) fl2 = 1;
        }
        if(fl){
            int k = a[n]-a[n-1];
            if(d >= 2*k){
                int x = d/k*2-1;
                cout<<max(0ll,n-x)<<'\n';
            }
            else cout<<0<<'\n';
        }
        else if(fl2){
            if(d == 2){
                int ans = 0;
                n-=3;
                while(n > 0){
                    ans+=n;
                    n-=2;
                }
                cout<<ans<<'\n';
            }
            else cout<<"0\n";
        }
        else{
            int ans = 0;
            for(int i=1;i<=n;++i){
                for(int j=i;j<=n;++j){
                    sum = 100000000,sumi = 0;
                    dfs(i,j,0);
                    if(sumi == 2) ++ans;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
//16 pts
