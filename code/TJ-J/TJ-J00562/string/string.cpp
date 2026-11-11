#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+7;
struct node
{
	int c;
	char f;
}n[maxn];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t,ans=0;
	cin >> t;
	vector<char> s;
	int id=0;
	char sa;
	bool fl=0;
	for(int i=0;i<t;i++)
	{
		cin >> n[i].c >> n[i].f;
		for(int j=1;j<=n[i].c;j++)
		{
			s.push_back(n[i].f);
			id++;
		}
	}
	int idx=id;
	idx--;
	for(int i=0;i<=idx;i++)
	{
		if(s[i]!=s[idx]) ans++;
		idx--;
	}
	cout << ans;
	return 0;
}
