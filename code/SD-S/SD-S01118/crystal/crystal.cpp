#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],s[N],sum,ans=1,cnt=1;//kai long long
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long l=1,r=2;r<=n;r++)
	{
		sum+=(a[r]-a[r-1])*cnt;
		cnt++;
		while(sum>m)
		{
			sum-=a[r]-a[l];
			cnt--;
			l++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
