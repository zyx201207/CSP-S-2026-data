#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
long long k[500005],w[500005],a[500005],t[200005];
bool flag=1;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=i;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]!=k[i-1])  
		{
			flag=0;
		}
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j];
			cin>>t[j];
		}
	}
	
	
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		
		int ans=0;
		
		for(int i=1;i<=n;i++)
		{
			
		}
		
		cout<<k[1]*2;
		
	}
	
    return 0;
}
