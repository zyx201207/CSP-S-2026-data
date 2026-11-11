#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int P=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10,M=2e6+10;
string a,b,c,d,ans="0000";
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		ans="1000";
		if(b[0]==d[0]&&b[1]==d[1])
		{
			ans="1100";
			char p=b[2],q=d[2];
			if((p<='C'&&q<='C')||(p>'C'&&q>'C'))
			{
				ans="1110";
				if(p>q)swap(p,q);
				string t="";
				t+=p;
				t+=q;
				if(t=="AB"||t=="BC"||t=="DF")
				{
					ans="1111";
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

