#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll a[500005];
ll b[500005];
ll sum[500005];
ll ans = 1;
bool flagA = true;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(i !=a[i])
		{
			flagA = false;
		}
	}
	
	sort(a+1,a+n+1);
	for(int i = 1;i<=n-1;i++)
	{
		b[i] = a[i+1] - a[i];
	}
	sum[1] = 0;
	for(int i = 1;i<=n;i++)
	{
		sum[i] = sum[i-1]+(i-1)*b[i-1];//sum[i]表示将前i个全部转化为ai的消耗
	}
	
	ll head = 1;
	ll tail = 1;
	
	while(tail<=head && tail<=n && head<=n)
	{
		ll bcur = 0;
		ll bans = 0;
		if(flagA)
		{
			bans = (2*head-1-a[tail-1])>>1;
			bans*=(tail-1);
		}
		else
		{
			for(int i = tail-1;i>0;i--)
			{
				bcur+=b[i];
				bans+=bcur+b[i];
			}
		}
		if(head == tail && head<n && sum[head+1] - bans-(tail-1)*b[head]>m)
		{
			head++;
			continue;
		}
		while(head<n && sum[head+1] - bans -(tail-1)*b[head]<=m)
		{
			head++;
		}
		if(sum[head]-bans <=m)
		{
			ans = max(ans,head-tail+1);
		}
		tail++;
	}
	cout<<ans;
	return 0;
}