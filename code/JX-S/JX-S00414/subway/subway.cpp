#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,w[100005],a[100005][100005],t[10005][10005];
struct road{
    int x,y;
}r[10005];
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    cin>>k;
    for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
    for(int i=1;i<=q;i++)cin>>r[i].x>>r[i].y;

    return 0;
}
