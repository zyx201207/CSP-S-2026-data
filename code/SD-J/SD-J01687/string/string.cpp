#include<bits/stdc++.h>
#define N 200010
#define int long long
using namespace std;
int n; 
int a[N];
char c[N];
string s;
int ans;
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
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	int ans=0,l=s.size();
	for(int i=0;2*i<=l;i++)
	{
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans;
	return 0; 
}
