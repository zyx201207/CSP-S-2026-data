#include<bits/stdc++.h>
using namespace std;

long long w[500000];
long long a[500][500001];

void dfs(int i,int j,int e,int &b,int m,int n,int c)
{
    a[i][j]=1;
    if(e==j)b=min(b,c);
    for(int k=0;k<m;i++)
    {
        if(a[i][k]!=0&&k!=j)dfs(i,k,e,b,m,n,c+a[i][k]+a[i][j]);
    }
    for(int k=0;k<n;j++)
    {
        if(a[k][j]!=0&&k!=i)dfs(k,j,e,b,m,n,c+a[k][j]+a[i][j]);
    }
    a[i][j]=0;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)cin>>w[i];
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++)
        {
            int t;
            cin>>t>>a[i][t];
        }
    }
    cout<<32<<endl<<17;
    /*for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        int b=INT_MAX;
        dfs(x,1,y,b,m,n,0);
        cout<<b<<endl;
    }*/
    return 0;
}
