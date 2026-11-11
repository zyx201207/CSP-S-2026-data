#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int t[505][2];
long long ans=0;
int main()
{
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
    {

        cin>>w[i];
    }

    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for (int j=1;j<=k;i++)
        {
            int f;
            cin>>f>>t[i][j];
        }
    }
    for (int i=1;i<=q;i++)
    {
        int s,e;
        cin>>s>>e;
        cout<<s*e*2;
    }
}
