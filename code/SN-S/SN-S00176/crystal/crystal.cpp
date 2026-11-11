#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,mx;
ll m;
ll a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==0)
	{
		for(int i=1;i<=n;i++)
		{
			int ans=1;
			while(a[i]==a[i+1])ans++,i++;
			mx=max(ans,mx);
		}
		cout<<mx;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ll x=m;
		int cnt=1,ans=1;
		while(x>0&&i-cnt>0)
		{
			if(x>=a[i]-a[i-cnt])x-=a[i]-a[i-cnt];
			else break;
			ans++,cnt++;
		}
		mx=max(ans,mx);
	}
	cout<<mx;
	return 0;
}
