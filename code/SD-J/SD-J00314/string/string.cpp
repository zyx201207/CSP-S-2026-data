#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
string s; 
int n;
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
		int x;
		char c;
		cin>>x;
		cin>>c;
		for(int j=1;j<=x;j++)
		{ 
			s+=c;
		} 
	}
	string s2;
	s2=s;
	reverse(s.begin(),s.end());
	int len=s2.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s2[i])ans++; 
	}
	cout<<ans/2<<'\n'; 
	return 0;
}

