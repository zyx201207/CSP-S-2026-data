#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
map<long long,int>mp;
pair<long long,int>p[N];
long long a[N];
bool cmp(pair<long long,int>a,pair<long long,int>b)
{
	return a.first<b.first;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		mp[x]++;
	}
	long long cnt=0,maxn=0,maxc=0,maxp=0;
	for(auto x:mp)
	{
		p[cnt].first=x.first;
		p[cnt].second=x.second;
		if(maxn==0||x.second>maxc)
		{
			maxn=x.first;
			maxc=x.second;
			maxp=cnt;
		}
		cnt++;
	}
	sort(p,p+cnt,cmp);
	pair<long long,int>p1[N];
	for(int i=0;i<cnt;i++)
		p1[i].first=p[i].first,p1[i].second=p[i].second;
	long long ans1=maxc;
	long long mm=m;
	for(int i=maxp-1;i>=0;i--)
	{
		while(p1[i].second>=1)
		{
			mm-=(maxn-p1[i].first);
			if(mm>=0)
			{
				ans1++;
				p1[i].second--;
			}
			else
				break;
		}
		if(m<0)
			break;
	}
	mm=m;
	long long ans2=mp[n/2];
	for(int i=n/2-1;i>=0;i--)
	{
		while(p[i].second>=1)
		{
			mm-=(maxn-p[i].first);
			if(mm>=0)
			{
				ans2++;
				p[i].second--;
			}
			else
				break;
		}
		if(m<0)
			break;
	}
	cout<<max(ans1,ans2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
