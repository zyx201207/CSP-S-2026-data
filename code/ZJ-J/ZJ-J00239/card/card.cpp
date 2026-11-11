#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<long long> ans(m+1,0);
	for(int id=1;id<=n;id++)
	{
		vector<long long> s;
		unordered_map<long long,long long> mapp;
		for(int i=id;i<=n;i++)
		{
			if(mapp[a[i]])
			{
				while(s.back()!=a[i])
				{
					mapp[s.back()]--;
					s.pop_back();
				}
			}
			else
			{
				mapp[a[i]]++;
				s.push_back(a[i]);
			}
		}
		for(int i=0;i<s.size();i++)
		{
			ans[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}