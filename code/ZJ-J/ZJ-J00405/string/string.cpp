#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct point
{
	ll a;
	char c;
}s[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].c;
	ll ans=0;
	ll l=1,r=n;
	while (l<r)
	{
		if (s[l].a==0)
			l++;
		if (s[r].a==0)
			r--;
		if (s[l].c!=s[r].c)
			ans+=min(s[l].a,s[r].a);
		if (s[l].a<=s[r].a)
		{
			s[r].a-=s[l].a;
			s[l].a=0;
		}
		else if (s[l].a>s[r].a)
		{
			s[l].a-=s[r].a;
			s[r].a=0;
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
