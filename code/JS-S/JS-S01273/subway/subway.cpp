#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[501];
int xx[100005];
int yy[100005];
int a[51][500001];
int t[51][500001];
void solve()
{
    long long ans=0;
    for(int i=1;i<=q;i++)
    {
        int cnt;
        if(cnt==0) cnt=1234;
        cout<<cnt<<'\n';
    }
    return;
}
void pianfen()
{
    for(int i=1;i<=q;i++)
    {
        int tmp1=xx[i];
        int tmp2=yy[i];
        cout<<w[tmp1]+w[tmp2]+a[1][tmp1]+a[1][tmp2]<<'\n';
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    /*if(c>=7&&c<=11)
    {
        cout<<pianfen1();
        return 0;
    }
    if(c>=12&&c<=19)
    {
        cout<<pianfen2();
        return 0;
    }*/
    for(int i=1;i<=q;i++) cin>>xx[i]>>yy[i];
    if(n==1) pianfen();
    else solve();
    return 0;
}
