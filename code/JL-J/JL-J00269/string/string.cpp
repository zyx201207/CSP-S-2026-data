#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,ans=0;
	cin>>n;
	int cnt[N];
	char c[N];
	for(int i=0;i<n;i++)
	{
		cin>>cnt[i]>>c[i];
	}
	int l=0,r=n-1;
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			int minn=min(cnt[l],cnt[r]);
			cnt[l]-=minn,cnt[r]-=minn;
			if(cnt[l]<cnt[r])
				l++;
			else if(cnt[l]>cnt[r])
				r--;
			else
				l++,r--;
		}
		else
		{
			int minn=min(cnt[l],cnt[r]);
			cnt[l]-=minn,cnt[r]-=minn;
			ans+=minn;
			if(cnt[l]<cnt[r])
				l++;
			else if(cnt[l]>cnt[r])
				r--;
			else
				l++,r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
