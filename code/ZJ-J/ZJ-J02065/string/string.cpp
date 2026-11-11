#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+3;
int n,ans,a[N];
char t[N];
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>t[i];
		for(int j=1;j<=a[i];j++)s+=t[i];
	}
	int len=s.size();
	s=" "+s;
	for(int i=1;i<=len/2;i++)
	{
		if(s[i]!=s[len-i+1])ans++;
	}
	cout<<ans;
}