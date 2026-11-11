#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,m,a[N],ans,vis[N],dis[N];
long long mi[N],cnt[N];
vector<int>g[N];
void dfs(int u,int st){
    if(mi[u]>st){
        mi[u]=st;
        cnt[u]=1;
    }else if(mi[u]==st){
        cnt[u]++;
    }
    for(int i=u+1;i<=n;i++){
        if(abs(a[i]-a[u])<=m){
            dfs(i,st+1);
        }else{
            break;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=9){
            for(int i=1;i<=n;i++){
                mi[i]=(long long)1e18;
                cnt[i]=0;
            }
            ans=0;
            for(int i=1;i<=n;i++){
                dfs(i,0);
                for(int j=i;j<=n;j++){
                    if(cnt[j]==2){
                        ans++;
                    }
                    mi[j]=(long long)1e18;
                    cnt[j]=0;
                }
            }
            cout<<ans<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
    return 0;
}
