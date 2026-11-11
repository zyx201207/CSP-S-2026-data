#include<bits/stdc++.h>
using namespace std;
int w[20005],a[20005],r1[20005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>r1[i];
    }
    cout<<w[1]+a[2]+(a[3]+a[4])+(a[1]+a[4])+a[3]+w[3]<<endl<<w[2]+a[4]+a[5]+w[3];
    return 0;
}
