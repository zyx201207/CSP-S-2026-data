#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
pair<long long,long long> p[500005];
int main()
{
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		long long k;
		cin>>k;
		mp[k]+=1;
	}
	long long sum=0;
	for(auto &i:mp)
	{
		p[sum].first=i.second;
		p[sum].second=i.first;
		sum++;
	}
	sort(p,p+sum);
	pair<long long,long long> p1;
	p1.first=p[sum-1].first;
	p1.second=p[sum-1].second;
	long long now=sum-2,num=0;
	while(m>=0)
	{
		if(p[now].second>p1.second)
		{
			now-=1;
		}
		else if(p[now].second==p1.second)
		{
			while(p[now].first>0)
			{
				num+=p[now].first;
				p[now].first-=1;
			}
			now-=1;
		}
		else
		{
			while(m>=0&&p[now].first>0)
			{
				m-=p1.second-p[now].second;
				num+=1;
				p[now].first-=1;
			}
			if(m<0)
			{
				num-=1;
			}
			now-=1;
		}
	}
	num+=p1.first;
	cout<<num;
	return 0;
}
