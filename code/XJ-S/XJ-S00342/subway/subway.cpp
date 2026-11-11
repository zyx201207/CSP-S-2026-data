#include<bits/stdc++.h> 
using namespace std;
int a[5005][5005]={0},i,j,k,s,e,ans;
int c,n,m,d,q;
int w[5005],t[5005][5005],x[5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int cnt=0;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		
		for(j=1;j<=k;j++)
		{
			cin>>x[j]>>t[i][j];
			cnt+=t[i][j];
		}
	}
	while(q--)
	{
		cin>>s>>e;
		ans=(w[s]+w[e]+cnt);
		cout<<ans;
	}
	return 0;
}
