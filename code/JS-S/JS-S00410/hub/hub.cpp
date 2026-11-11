#include<bits/stdc++.h>
using namespace std;
int c,_;
long long n,k;
vector <int> G[500005];
long long sz[500005][2],maxn;
void dfs(int u,int fa){
    sz[u][0]=1;
    for (auto v:G[u]){
        //cout<<v<<endl;
        if (v==fa) continue;
        dfs(v,u);
        if (sz[v][0]+1>sz[u][0]){
            sz[u][1]=sz[u][0];
            sz[u][0]=sz[v][0]+1;
        }
        else if (sz[v][0]+1>sz[u][1]){
            sz[u][1]=sz[v][0]+1;
        }
    }
    //cout<<u<<' '<<sz[u][0]<<' '<<sz[u][1]<<endl;
    maxn=max(maxn,sz[u][0]+sz[u][1]-1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>_;
    while (_--){
        cin>>n>>k;
        for (int i=1;i<=n;i++){
            G[i].clear();
            sz[i][0]=sz[i][1]=0;
            maxn=0;
        }
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,0);
        if (c==13 || c==14){
            int m=(n-1)/2+2;
            if (k==1) cout<<(m+1/2)-1<<"\n";
            else{
                int jian=((k-2)/3);
                cout<<(m-2)/3+1-jian<<"\n";
            }
        }
        else if (c==1){
            if (k==1) cout<<(maxn)/2<<"\n";
            else if (k!=n) cout<<"1\n";
            else cout<<"0\n";
        }
        else if (c==7 || c==11 || c==12){
            if (k==1) cout<<(maxn)/2<<"\n";
            else cout<<maxn/3<<"\n";
        }
        else{
            int jian=((k-2)/3);
            if (k==1) cout<<(maxn)/2<<"\n";
            else cout<<maxn/3-jian<<"\n";
        }
    }
    return 0;
}
