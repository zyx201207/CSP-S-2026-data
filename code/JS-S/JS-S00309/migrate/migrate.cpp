#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[200005],ans,an,st;
vector<int>edges[5005];
void dfs(int X,int y,int k){
    if(X>y){
        return;
    }
    if(y==X){
        st=min(st,k);
        return;
    }
    for(auto s:edges[X]){
        dfs(s,y,k+1);
    }
}
void dfs2(int X,int y,int k,int step){
    if(X>y){
        return;
    }
    if(k>step){
        return;
    }
    if(an>2){
        return;
    }
    if(y==X){
        an++;
        return;
    }
    for(auto s:edges[X]){
        dfs2(s,y,k+1,step);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    while(t--){
        st=1e18;
        ans=0,an=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            edges[i].clear();
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d)
                    edges[i].push_back(j);
                else    break;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                st=1e18;
                an=0;
                dfs(i,j,0);
                dfs2(i,j,0,st);
                if(an==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
