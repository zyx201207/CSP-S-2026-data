#include <bits/stdc++.h>
using namespace std;
long long cnt,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char y;
		cin>>x>>y;
		for(int i=ans;i<=ans+x;i++)
		{
			s[i]=y;
		}
		ans+=x;
	}
	for(int i=0;i<=ans/2;i++)
	{
		if(s[i]!=s[ans-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
