#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long n,m;
long long a[MAXN];
void solve1()
{	
	sort(a+1,a+n+1);
	long long cost=0;
	int ans=0;
	int st=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
			continue;
		cost+=(a[i]-a[i-1])*(i-st);
		ans=max(ans,i-st);
		if(cost>m)
		{
			while(cost>m&&st<=i)
			{
				cost-=a[i]-a[st];
				st++;
				if(cost<=m)
					break;
			}
		}
	}
	ans=max(ans,(int)n-st+1);
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		solve1();
	return 0;
}