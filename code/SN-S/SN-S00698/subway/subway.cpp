#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l,r,ans=0;
	l=1;
	r=n;
	while(l<=r)
	{
		long long mid=(r+l)/2;
		long long cnt=0;
		long long cnts=0;
		for(int i=mid;i>=1;i--)
		{
			cnts=cnts+a[mid]-a[i];
			if(cnts>m)
			{
				break;
			}
			cnt++;
		}
		if(cnts<=m)
		{
			ans=max(ans,cnt);
			l=mid+1;
		}
		else
		{
			ans=max(ans,cnt);
			r=mid-1;
		}
	}
	cout<<ans; 
	return 0;
} 
