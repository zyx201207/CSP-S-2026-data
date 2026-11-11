#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			s+=y;
		}
	}
	
	for(int i=0,j=s.size()-1;i<j;i++,j--)
	{
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
