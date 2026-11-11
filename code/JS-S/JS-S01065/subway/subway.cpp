#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[505][500005],a0[505];
struct n1{
    int x,y;
}r[100005];
struct n2{
    int ai,ti;
}a[505][500005];
void dfs(int s,int e){
    int cnt=0;
    c=w[s]+w[e];
    cout<<c;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>a0[i];
        for(int j=1;j<=a0[i];j++)cin>>a[i][j].ai>>a[i][j].ti;
    }
    for(int i=1;i<=q;i++){
            cin>>r[i].x>>r[i].y;
            dfs(r[i].x,r[i].y);
    }
    return 0;
}
