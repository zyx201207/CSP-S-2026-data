#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    int w[1000000000];
    int a[500];
    int b[1000000008];
    int t[1000000008];
    int e,f;
    int z=0;
    int x=0;
    int y;
    int g;
    for(int i=0;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
        x+=a[i];
    }
    for(int i=0;i<=x;i++)
    {
        cin>>b[i];
        cin>>t[i];
    }
    for(int i=0;i<=x;i++)
    {
        for(int j=i+1;j<=x;j++)
        {
            if(b[i]==b[j])
            {
                y=i;
                g=j;
            }
        }
    }
    for(int i=0;i<=p;i++)
    {
        cin>>e>>f;
        z+=w[e-1];
        for(int j=0;j<=x;j++)
        {
            if(b[j]==e)
            {
                z+=t[j];
            }
            if(b[j]==f&&j>a[i])
            {
                z+=t[y];
                z+=t[g];
                z+=t[j];
                z+=w[f-1];
            }
            if(b[j]==f&&j<a[i])
            {
                z+=t[j];
                z+=w[f-1];
            }
        }
        cout<<z<<endl;
    }
    return 0;
}
