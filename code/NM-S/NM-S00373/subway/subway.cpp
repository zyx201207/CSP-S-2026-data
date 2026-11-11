#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[999999],k[999999],a[999999][999999];
ll t[999999][999999],x[999999];
ll y[999999],ans[999999];
int main()
{
    freopen("subway.in",r,stdin);
    freopen("subway.out",w,stdout);
    ll c,n,m,d,q,s;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++)
    {
    	cin>>k[i];
    	for(ll j=1;j<=k[i];j++)
    	{
    		cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++)
    {
    	cin>>x[r]>>y[r];
	}
	for(int i=1;i<=k[1];i++)
	{
		for(int j=1;j<=k[2];j++)
		{
			if(a[1][i]==a[2][j])
				{
					s=a[1][i];	
				}
		}
	}
	for(ll r=1;r<=q;r++)
	{
		ans[r]=w[x[r]]+t[1][x[r]]+t[1][s]+t[2][s]+t[2][y[r]]+w[y[r]];
		cout<<ans[r]<<endl;
	}
    return 0;
}
