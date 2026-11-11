#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	ll ans=1;
	ll l=1,r=1;
	while(l<=r&&r<=n)
	{
		ll sd=a[r]*(r-l+1);
		if(sd<=s[r]-s[l-1]+m)
		{
			//cout<<l<<' '<<r<<'\n';
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
// rrrrrrrrrrrrrr       pppppppppppppp				+						+
// rr           rr		pp			 pp				+  						+
// rr            rr		pp			  pp			+						+
// rr           rr		pp  		 pp				+						+
// rrrrrrrrrrrrr		pppppppppppppp				+                       +
// rrrrrr				pp				   ++++++++++++++++++++   ++++++++++++++++++++
// rr    rr				pp	              			+						+
// rr      rr			pp							+						+
// rr        rr			pp							+						+	
// rr          rr		pp							+						+
// rr            rr		pp							+						+
//14:55 ac1

