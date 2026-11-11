#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=5e5+5;

int c,n,m,d,q;
int W[N],k[N],a[505][N],t[505][N],x[N],y[N];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>W[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
    return 0;
}