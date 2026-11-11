#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=-1;
int a[500050];
bool A=true,b=true;
int b1;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=i) A=false;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		if(a[i-2]-a[i-1]!=a[i-1]-a[i]) b=false;
	}
	if(A)
	{
		for(int i=1;m>=0;i++)
		{
			m-=i;
			ans=i;
		}
		cout<<ans;
		return 0;
	}
	if(b)
	{
		m/=(max(a[2],a[1])-min(a[2],a[1]));
		ans=1;
		for(int i=1;m>=0;i++) 
		{
			m-=i;
			ans=i;
		}
		cout<<ans;
		return 0;
	} 
	for(int i=1;i<=n;i++) 
	{
		int tmp=1,j=i-1,money=m;
		while(money>=abs(a[j]-a[i])&&j>=1)
		{
			money-=abs(a[j]-a[i]);
			tmp++;
			j--;
		}
		ans=max(ans,tmp);
	} 
	cout<<ans;
	return 0;
}
 
