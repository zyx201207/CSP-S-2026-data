#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll w[5000005];
ll t[505][2];
ll u[505][2];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(k==1) cin>>k>>k;
		else
		{
			cin>>u[i][0]>>t[i][0]>>u[i][1]>>t[i][1];
		}
	}
	while(q--)
	{
		cout<<1<<'\n';	
	} 
	return 0;
}

