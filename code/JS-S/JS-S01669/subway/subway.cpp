#include<bits/stdc++.h>
using namespace std;
int h[100101],w[100101],a[5010][5010],t[5010][5010];
int cnt=1,ma=INT_MAX;
struct st{
    int to,nxt;
};
st E[10101];
void build(int u,int v){
    E[cnt].to=v;
    E[cnt].nxt=h[u];
    h[u]=cnt;
    cnt++;
}
void solve(int x,int y,int z){
    if(x==y){
        ma=min(ma,z+w[y]);
        return;
    }
    for(int j=h[x];j!=0;j=E[j].nxt){
        solve(E[j].to,y,z+t[x][E[j].to]);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
           // t[j][i]=t[i][j];
            if(j!=1)build(a[i][j-1],a[i][j]);
        }
    }
    //cout<<t[2][3]<<endl;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        solve(x,y,w[x]+t[x][x]);
        cout<<ma<<endl;
    }
    return 0;
}
