#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int c,t,n,k,vis[15],vv[15],de[15],ans=0x3f3f3f3f;
vector<int> g[N+5];
void dfs(int u,int fa){
    vv[u]=1;
    for(int i=0;i<g[u].size();i++){
        if(!vis[g[u][i]]){
            continue;
        }
        if(!vv[g[u][i]]){
            vv[g[u][i]]=1;
            if(g[u][i]!=fa){
                dfs(g[u][i],u);
            }
        }
    }
}
int dd(int u,int fa){
    if(vis[u]){
        de[u]=0;
        return 0;
    }
    if(de[u]!=0x3f3f){
        return de[u];
    }
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa){
            continue;
        }
        de[u]=min(de[u],dd(g[u][i],u)+1);
    }
    return de[u];
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        ans=0x3f3f3f;
        for(int i=1;i<n;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v),g[v].push_back(u);
        }
        if(k==n){
            cout << 0 << "\n";
        }else if(k==n-1){
            cout << 1 << "\n";
        }else if(n<=10){
            for(int p=0;p<pow(2,n);p++){
                int cnt=0;
                for(int i=0;i<n;i++){
                    vis[i+1]=0,vv[i+1]=0,de[i+1]=0x3f3f;
                    if((p>>i)&1){
                        cnt++;
                    }
                }
                //cout << cnt << " ";
                if(cnt!=k){
                    continue;
                }
                for(int i=0;i<n;i++){
                    vis[i+1]=(p>>i)&1;
                }
                int ccnt=0;
                bool ff=true;
                for(int i=1;i<=n;i++){
                    if(vis[i] && !vv[i]){
                        ccnt++;
                        if(ccnt>2){
                            ff=false;
                            break;
                        }
                        dfs(i,0);
                    }
                }
                //cout << ccnt << " ";
                if(ff){
                    int maxx=-1;
                    for(int i=1;i<=n;i++){
                        maxx=max(maxx,dd(i,0));
                    }
                    //cout << maxx << " ";
                    ans=min(ans,maxx);
                }
            }
            cout << ans << "\n";
        }else if(k>=n/2){
            cout << 1 << "\n";
        }else{
            cout << 1+(n/2-k) << "\n";
        }
    }
    return 0;
}