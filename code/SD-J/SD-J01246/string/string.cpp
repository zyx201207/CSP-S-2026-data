#include<bits/stdc++.h>
#define int long long
using namespace std;
string ss;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum;
	char s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sum>>s;
		for(int j=1;j<=sum;j++)
		{
			ss+=s;
		}
	}
	int ans=0;
	for(int i=0,j=ss.size()-1;i<=j;i++,j--)
	{
		if(ss[i]!=ss[j])ans++;
	}
	cout<<ans;
	return 0;
}
