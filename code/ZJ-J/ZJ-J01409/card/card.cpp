#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int M=500000+10;
ll a[M],n,m,i,j;
map<ll,ll> cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		list<ll>lt;
		map<ll,list<ll>::iterator>mp;
		for(j=i;j<=n;j++)
		{
			if(mp.count(a[j])!=0)
			{
				auto ix=mp[a[j]];
				for(auto ir=ix;ir!=lt.end();ir++)
					mp.erase(*ir);
				lt.erase(ix,lt.end());
			}
			lt.push_back(a[j]);
			mp.insert(make_pair(a[j],--lt.end()));
		}
		for(auto it=lt.begin();it!=lt.end();it++)
		{
			cnt[*it]++;
//			cout<<*it<<" ";
		}
//		cout<<endl;
	}
	for(i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
        