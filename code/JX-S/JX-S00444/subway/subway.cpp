#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e4+1,N=501;
int c,m,n,d,q,ans=LLONG_MAX;
int w[N];
int a[N][M];
int t[N][M];
int vis[N][M];
int b[M];
int k[N];
void ddd(int x,int y,int i,int num,int kkk){
    if(x<1||y>kkk)return;
    num+=t[i][x];
    if(a[i][x]==y){
        ans=min(ans,num+w[y]);
        return ;
    }
    if(b[a[i][x]]>1){
        for(int j=1;j<=k[j]&&j!=i;j++)
            if(vis[a[i][x]][j]!=0)ddd(x,y,j,num+t[i][x]+t[j][x],k[i]);
    }
    ddd(x+1,y,i,num,kkk);
    ddd(x-1,y,i,num,kkk);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int poki;
            cin>>a[i][k[i]]>>t[i][k[i]];
            b[a[i][k[i]]]++;
            if(vis[a[i][k[i]]][poki++]==0)vis[a[i][k[i]]][poki]=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(b[a[i][k[i]]]>d)return 0;
    }
    while(q--){
        int x,y;cin>>x>>y;
        ddd(x,y,1,w[1],k[]);
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
