#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
int c,T,n;
ll d;
ll a[N];
namespace aaa{
    int ans=0,cnt,minn;
    void dfss(int x,int en,int sum){
        if(x==en){
            minn=min(minn,sum);
            return;
        }
        for(int i=x+1;i<=en;i++){
            if(a[i]-a[x]>d) break;
            dfss(i,en,sum+1);
        }
    }
    void dfs(int x,int en,int sum){
        if(x==en){
            if(sum==minn) cnt++;
            return;
        }
        for(int i=x+1;i<=en;i++){
            if(a[i]-a[x]>d) break;
            dfs(i,en,sum+1);
        }
    }
    void solve(){
        ans=0;
        minn=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                cnt=0;minn=INT_MAX;
                dfss(i,j,0);
                dfs(i,j,0);
                if(cnt==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c<=6){
            aaa::solve();
            continue;
        }
    }
    return 0;
}
