#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>mp;
string s;
static inline string solve(int x)
{
	map<char,int>m;
	string res;
	for(int i=x-1;i<s.size();i++)
	{
		if(m[s[i]]==0)
		{
			//if(x==2)cout<<s[i]<<'p'<<'\n';
			res.push_back(s[i]);
			m[s[i]]++;
		}
		else
		{
			//if(x==2)cout<<s[i]<<'u'<<'\n';
			int id = res.find(s[i]);
			//if(x==2)cout<<id<<'\n';
			string u = res.substr(0,id);
			//if(x==2)cout<<u<<'\n';
			for(int j=id+1;j<res.size();j++)m[res[j]]=0;
			res = u;
			res.push_back(s[i]);
		}
	}
	return res;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s.push_back(x+'0');
	}
	for(int i=1;i<=n;i++)
	{
		string p = solve(i);
		//cout<<p<<'\n';
		for(int i=0;i<p.size();i++)
		{
			mp[p[i]-'0']++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mp[i]<<' ';
	}
	return 0;
}
