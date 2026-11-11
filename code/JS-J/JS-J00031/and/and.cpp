#include<bits/stdc++.h>
using namespace std;
int b[200010];
int a[200010][2];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    a[1][1]=b[1];
    for(int i=2;i<=n;i++)
    {
        a[i][1]=max(a[i-1][1],b[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=i;j++)
        {
            a[i][j]=max(a[i-1][(j-1)%2]&b[i],a[i-1][j%2]);
        }
    }
    cout<<a[n][m];
    return 0;
}
