#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,set<int>>mp;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		string s;
		while(x)
		{
	//		if(x&1)
			s.push_back(x%2+'0');
			x/=2;
		}
	//	reverse(s.begin(),s.end());
//		cout<<s<<" \n";
		for(int j=0;j<s.size();j++)
			if(s[j]-'0'!=0)
				mp[j].insert(i);
	}
//	for(int i=0;i<=6;i++)cout<<mp[i].size()<<" ";
	set<int>st;
	int pl=0;
	for(int x=31;x>=0;x--)
	{
		if(mp[x].size()>=m)
		{
			st=mp[x];
			pl=x;
			break;
		}
	}
//	cout<<pl<<" ";
	int res=0;
	for(int x=pl;x>=0;x--)
	{
		set<int>stt;
		int tk=0;
		for(auto it:mp[x])
		{
			if(st.count(it))
			{
				stt.insert(it);
				tk++;
			}
		}
		if(tk>=m)
		{
			st=stt;
			res+=(1<<x);
		}
	}
	cout<<res;
}
