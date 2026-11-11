#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a,cnt;
char c;
string s;
signed main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	for(int i=0,j=s.size()-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j]) 
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
