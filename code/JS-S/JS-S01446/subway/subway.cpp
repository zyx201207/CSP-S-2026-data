#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,bg,en,mi=INT_MAX;
int kt[500005],tt[505][50005],vis[500005],zt[500005];
vector<int> dt[505][50005];
void find(int la,int sz){
    if(la==en){
        mi=min(sz,mi);
        return ;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<dt[i][la].size();j++){
            if(vis[la]==1) continue;
            vis[la]=1;
            find(dt[i][la][j],sz+tt[i][la]+tt[i][dt[i][la][j]]);
            vis[la]=0;
        }
    }
    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>kt[i];
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int a,t;
            cin>>a>>t; 
            tt[i][a]=t;
            zt[j]=a;
            for(int k=1;k<j;k++){
                dt[i][zt[k]].push_back(a);
                dt[i][a].push_back(zt[k]);
            }
        }
        memset(zt,0,sizeof(zt));
    }
    for(int i=1;i<=q;i++){
        cin>>bg>>en;
        find(bg,0);
        cout<<kt[bg]+kt[en]+mi<<'\n';
        mi=INT_MAX;
    }
    return 0;
}