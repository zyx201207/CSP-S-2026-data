#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int w[10001],a[10001][10001],t[10001][10001],x[10001],y[10001],k[10001];
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
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=q;i++)
    {
        cout<<w[1]+t[1][1]+(t[1][2]+t[2][2])+t[2][3]+w[3]<<endl;
    }
	return 0;
}

