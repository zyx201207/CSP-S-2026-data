#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long sum=0,now=1,ans=1,cnt=1;
	for(int i=2;i<=n;i++)
	{
		sum+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(sum>m)
		{
			sum-=a[i]-a[now];
			now++,cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
