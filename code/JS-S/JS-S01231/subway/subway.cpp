#include<bits/stdc++.h>
using namespace std;
int w[500010];
vector<int> a[510];
vector<int> t[510];
vector<int> vis[510];
int mini=INT_MAX;
int cnt=0;

void dfs(int nown,int mudi){
    for(auto p:a[nown]){
        if(p==mudi){
            mini=min(mini,cnt+t[nown][nown]+t[nown][mudi]);
            return;
        }
    }
    for(int i=0;i<a[nown].size();i++){
        if(a[nown][i]!=nown){
            if(!vis[nown][i]){
                cnt+=t[nown][nown]+t[nown][mudi];
                vis[nown][i]=1;
                dfs(a[nown][i],mudi);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int ki;
        cin>>ki;
        for(int j=1;j<=ki;j++){
            int b,l;
            cin>>b>>l;
            a[j].push_back(b);
            vis[j].push_back(0);
            a[b].push_back(j);
            vis[b].push_back(0);
            t[j].push_back(l);
            t[i].push_back(l);
        }
    }
    for(int i=1;i<=q;i++){
        mini=INT_MAX;
        int x,y;
        cnt=0;
        cin>>x>>y;
        dfs(x,y);
        cout<<mini+w[x]+w[y]<<'\n';
    }
    return 0;
}
