#include<bits/stdc++.h>
using ll=long long;
using namespace std;

const int maxn=5e5+10;

int n,m;
int a[maxn],fa[maxn],sizee[maxn];
unordered_map<string,int> mp,tot;
string s[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int wei=30;wei>=0;wei--)
	{
		int cs=0;
		for(int i=1;i<=n;i++)
			if(a[i]&(1<<wei))cs++;
		if(cs>=m)
		{
			vector<int> v;
			for(int i=n;i>=1;i--)
				if(a[i]&(1<<wei))v.push_back(a[i]);
			int ans=v[0];
			for(int i=0;i<m;i++)ans=ans&v[i];
			cout<<ans;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
