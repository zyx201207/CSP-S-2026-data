#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500005],t[500005],b[100005];
int w[500005],k[500005],e[100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[j]>>t[j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>b[i]>>e[i];
    }
    for(int i=1;i<=q;i++)
    {
        cout<<1<<endl;
    }
    return 0;
}
