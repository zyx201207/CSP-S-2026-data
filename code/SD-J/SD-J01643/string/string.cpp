#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,char> > vc;
int n;
int ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)
		{
			s+=c;
		}
	}
	int l=0,r=s.size()-1;
	int ans=0;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			s[r]=s[l];
			ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
