#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,a[N],cnt[35];
multiset<int> s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) continue;
		int lg=__lg(a[i]);
		cnt[lg]++;
	}
	for(int i=33;i>=0;i--)
	{
		if(cnt[i]<m)
		{
			while(cnt[i])
			{
				int tmp=*(--s.end());
				s.erase(s.find(tmp));
				tmp%=(1<<i);
				cnt[i]--;
				if(tmp!=0)
				{
					cnt[__lg(tmp)]++;
					s.insert(tmp);
				}
			}
		}
		else
		{
			while(s.size()!=cnt[i])
			{
				int tmp=*(s.begin());
				s.erase(s.find(tmp));
				cnt[__lg(tmp)]--;
			}
			ans+=(1<<i);
			int tot=s.size();
			while(tot--)
			{
				int tmp=*(--s.end());
				s.erase(s.find(tmp));
				tmp%=(1<<i);
				cnt[i]--;
				if(tmp!=0)
				{
					cnt[__lg(tmp)]++;
					s.insert(tmp);
				}
			}
			// for(int i=30;i>=0;i--)
			// 	cout<<cnt[i]<<" ";
			// cout<<"\n";
		}
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/