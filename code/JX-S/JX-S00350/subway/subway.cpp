#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans;
int w[505];
struct N{
    int sta;
    int ti;
};
vector<N> sbw[505];
//bool vis[505];
void dfs(int x,int y,long long step){
    if(x==y){
        ans=min(ans,step);
        return;
    }
    if(step>ans)return;
    int sbwl=sbw[x].size();
    for(int i=0;i<sbwl;i++){
        //if(!vis[sbw[x][i].sta]){
        //    vis[sbw[x][i].sta]=1;
        dfs(sbw[x][i].sta,y,step+sbw[x][i].ti);
        //}
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        int a[505],t[505];
        for(int j=0;j<k;j++){
            cin>>a[j]>>t[j];
        }
        /*for(int j=1;j<k;j++){
            sbw[a[j-1]].push_back({a[j],t[j]+t[j-1]});
        }*/
        for(int j=0;j<k-1;j++){
            for(int p=j+1;p<k;p++){
                sbw[a[j]].push_back({a[p],t[j]+t[p]});
            }
        }
    }
    while(q--){
        //memset(vis,0,sizeof vis);
        ans=0x3f3f3f3f;
        int st,en;
        cin>>st>>en;
        dfs(st,en,0);
        cout<<ans+w[st]+w[en]<<endl;
    }
    return 0;
}
