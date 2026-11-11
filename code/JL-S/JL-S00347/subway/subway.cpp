#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[150000],k,a[505][150000],t[505][150000],r[2][100005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        cin>>w[i];
    }
    cin>>k;
    for(int i=0;i<2*k;i++)
    {
        for(int j=0;j<2*k;j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>r[i][j];
        }
    }
    while(q--)
    {
        cout<<w[r[q][1]]+t[r[q][1]][r[q][1]]+t[r[q][2]][r[q][2]]+w[r[q][2]];
    }
}
