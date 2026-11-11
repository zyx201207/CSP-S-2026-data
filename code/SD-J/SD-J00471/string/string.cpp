#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
string s;
int n,cnt;
char c;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)
		{
			s.push_back(c);
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			cnt++;
		}
		l++,r--;
	}
	cout<<cnt;
	return 0;
}
