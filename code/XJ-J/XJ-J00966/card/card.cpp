#include<bits/stdc++.h>
using namespace std;

int n,m,p,ans[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		ans[p]++; 
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
		
	}
	return 0;
}
