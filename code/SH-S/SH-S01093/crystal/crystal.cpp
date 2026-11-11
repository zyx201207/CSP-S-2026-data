#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,maxn=-1;
ll a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0,cnt=1;
	for(int i=1;i<=n;i++)
	{
		int x=(a[i+1]-a[i])*i;
		if(x<=m)
		{
			m-=x;
		}
		else
		{
			cnt=i;
			break;
		}
	}
	
	cout<<cnt;
	return 0;
 } 
