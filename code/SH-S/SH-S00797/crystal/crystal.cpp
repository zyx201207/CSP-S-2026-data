#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500015];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int head=1,tail=1,stk[500015],ans=0;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(tail-head)*(a[i]-a[i-1]);
		stk[tail]=i;
		tail++;
		while(head<tail&&sum>m)
		{
			sum-=(a[i]-a[stk[head]]);
			head++;
		}
		ans=max(ans,tail-head);
	}
	cout << ans;
	return 0;
} 
