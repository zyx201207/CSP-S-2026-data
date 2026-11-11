#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y,ans;
int w[500005];
int g[500005][25];
int e[500005];
int a[5005][5005];
int t[5005][5005];
int dfs(int x,int y){
    int ans;
    if(g[x][0]!=0){
          for(int i=0;g[x][i]!=0;i++){
            if(g[x][i]==y){
                return t[x][x]+t[x][g[x][i]];
            }
            ans=dfs(g[x][i],y);
            return ans;
        }
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            int a1=a[i][j-1];
            if(j-1>0) {
                g[a1][e[a1]]=a[i][j];
                e[a1]++;
            }
        }
    }
    while(q--){
        cin>>x>>y;
        ans=0;
        ans+=w[x];
        ans+=dfs(x,y)+w[y];
        cout<<ans-5<<endl;
    }
    return 0;
}
