#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	while(m--)
	{
		long long xx,yy;
		memset(arr,0,sizeof(arr));
		cin>>xx>>yy;
		for(int i=1;i<=xx;i++)
		{
			cin>>arr[i];
		}
  		if(arr[1+(xx/2)]-arr[1]<=yy&&xx>=2*yy)
  		{
  			cout<<xx-yy-(yy-1)<<'\n';
		}
		else
		{
			cout<<0<<'\n';
		}
	}
	return 0;
}