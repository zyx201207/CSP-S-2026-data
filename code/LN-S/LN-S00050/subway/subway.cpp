#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
int c,n,m,d,q;
vector<int> a[500005];
vector<int> v[500005];
vector<bool> vis[500005];
int x,y;
int mmin=9e18;
void dfs(int now,int cnt){
    if(now==y){
        cnt=min(cnt,mmin);
    }
    for(int i=0;i<a[now].size();i++){
        if(!vis[now][i]){
            vis[now][i]=1;
            dfs(i,cnt+v[now][i]);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int d,f;
            cin>>d>>f;
            a[i].push_back(d);
            v[i].push_back(f);
            vis[i].push_back(0);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        mmin=9e18;
        dfs(x,0);
        cout<<mmin<<'\n';
    }
    return 0;
}
