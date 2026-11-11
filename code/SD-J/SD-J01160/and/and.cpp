#include<bits/stdc++.h>
using namespace std;
const int MAXN=0x3f3f3f3f3f;
int a[200005],n,m,ans;
vector<int> cnt[35],d;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int b=a[i],j=0;
		while(b)
		{
			if(b%2==1) cnt[j].push_back(i);
			b/=2;
			j++;
		}
	}
	for(int i=0;i<=31;i++) sort(cnt[i].begin(),cnt[i].end());
	int st=31;
	while(cnt[st].size()<m&&st>=0) st--;
	for(int i=0;i<cnt[st].size();i++)
	{
		d.push_back(cnt[st][i]);
	}
	ans+=(1<<st);
	for(int i=st-1;i>=0;i--)
	{
		if(cnt[i].size()<m) continue;
		vector<int> ad(0);
		for(int j=0;j<d.size();j++)
		{
			int pos=lower_bound(cnt[i].begin(),cnt[i].end(),d[j])-cnt[i].begin();
			if(cnt[i][pos]==d[j]) ad.push_back(d[j]);
		}
		if(ad.size()<m) continue;
		ans+=(1<<i);
		d.resize(0);
		for(int j=0;j<ad.size();j++) d.push_back(ad[j]);
	}
	cout<<ans;
	return 0;
}
