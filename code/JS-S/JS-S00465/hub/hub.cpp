#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=2e6+5;
int c,T,n,k,ans,ipt[len];
int d[len];
vector<int> e[len];
void dfs(int dep,int i){
    if(dep==k+1){
        for(int i=1;i<=n;i++) d[i]=-1;
        queue<int> q;
        int cnt=0;
        for(int i=1;i<=k;i++){
            q.push(ipt[i]);
            d[ipt[i]]=0;
        }
        while(q.size()){
            int u=q.front();
            q.pop();
            cnt++;
            if(d[u]>=ans) return;
            if(cnt==n){
                ans=min(ans,d[u]);
                return;
            }
            for(int i=0;i<e[u].size();i++){
                int v=e[u][i];
                if(d[v]==-1){
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return;
    }
    for(i++;i<=n;i++){
        ipt[dep]=i;
        dfs(dep+1,i);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(n>=10){
            cout<<n/k/2<<'\n';
        }
        ans=n;
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
