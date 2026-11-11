#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,l,ans;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s='#';
	for(int i=1;i<=n;i++)
	{
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
		l+=a;
	}
	for(int i=1;i<=l;i++)
	{
		int t=l+1-i;
		if(s[i]!=s[t]) ans++;
		if(t==i) break;
	}
	cout<<ans<<"\n";
	return 0;
}
