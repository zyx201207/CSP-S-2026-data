#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
ll n,m,a[N],zy,cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0)
	{
		zy=n/2+1;
	}
	if(n%2!=0)
	{
		zy=(n+1)/2;
	}
	bool flag=1;
	for(int i=zy;i>=1;i--)
	{
		if(flag==1 && a[i]!=a[zy])
		{
			int z=a[zy]-a[i];
			if(m>=z)
			{
				m-=z;
				cnt++;
			}
			else flag=0;
		}
		if(a[i]==a[zy]) cnt++;
	}
	for(int i=zy+1;i<=n;i++)
	{
		if(a[i]==a[zy]) cnt++;
	}
	cout<<cnt;
	return 0;
} 
