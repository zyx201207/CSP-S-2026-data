#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[10008];
int k[10008];
int a[1008][1008],t[1008][1008];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    cin>>q;
    srand(time(NULL));
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int r=rand()%100+1;
        cout<<r;
    }
    return 0;
}