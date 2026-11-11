#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.in","w",stdout);
	//ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		//vector<ll> a(n+1,0);
		int flag=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ll dd=a[2]-a[1];
		if(d/dd!=2) 
			cout<<0<<'\n';
		else cout<<n-3<<'\n';
	} 
	return 0;
}

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

