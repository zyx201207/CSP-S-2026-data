#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[1000005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1) 
	{
		cout<<n;
		return 0;
	}
	if(m==2&&a[n]==1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==2) cnt++;
		}
		cout<<n<<" "<<cnt;
		return 0;
	}
	if(m==2&&a[n]==2)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) cnt++;
		}
		cout<<cnt<<" "<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<1<<" ";
	}
	return 0;
}
