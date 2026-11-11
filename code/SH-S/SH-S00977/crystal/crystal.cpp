#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005],pre[500005];
long long check(long long st,long long en)
{
	if(a[en] * (en - st) - (pre[en - 1] - pre[st - 1]) <= m) return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	for(int i = 1;i <= n;i++)
	{
		long long l = 1,r = i,pos;
		while(l <= r)
		{
			long long mid = (l + r) / 2;
			if(check(mid,i) == true) pos = mid,r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans,i - pos + 1);
	}
	cout<<ans<<endl;
	return 0;
}
