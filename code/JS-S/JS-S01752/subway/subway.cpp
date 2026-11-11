#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
int times[N];
struct node{
    int u,ti;
};
vector<node> a[N];
vector<int> lines[N];
bool h[N];
int ans,s,e;
void dfs(int l,int u,int sum){
    if(sum>=ans)
        return;
    if(u==e){
        ans=min(ans,sum);
        return;
    }
    for(int line:lines[u]){
        for(node station:a[line]){
            int v=station.u;
            int w=station.ti;
            if(l!=line) w+=a[line][v].ti;
            if(!h[v]||l!=line){
                h[u]=1;
                dfs(line,v,sum+w);
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>times[i];
    for(int i=1;i<=n;i++){
        int ki,u,ti;
        cin>>ki;
        for(int j=1;j<=ki;j++){
            cin>>u>>ti;
            a[i].push_back(node{u,ti});
            lines[u].push_back(j);
        }
    }
    while(q--){
        cin>>s>>e;
        ans=INT_MAX;
        for(int line:lines[s])
            dfs(line,s,0);
        int st=times[s]+times[e]+ans;
        cout<<st<<'\n';
    }
    return 0;
}
