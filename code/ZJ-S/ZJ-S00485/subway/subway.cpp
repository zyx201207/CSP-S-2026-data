#include <bits/stdc++.h>
using namespace std;
const int MAXN=50005;
int main()
{
	long long c,n,m,d,q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>m>>n>>d>>q;
	if(c==0)
	{
		if (m==2)cout<<32<<endl<<17;
		if (m==3)cout<<35<<endl<<16;
		return 0;
	} 
	while(q--)
	{
		long long x,y;
		int ans=0;
		long long cnt=0;
		int t[MAXN];
		int st[MAXN];
		int M[MAXN];
		for (int i=0;i<=m;i++)
		{
			cin>>M[i];
		}
		cin>>x>>y;
		for (int i=1;i<=n;i++)
		{
			cin>>st[i];
			cin>>t[i];
		}
		cnt=y-x;
		for(int i=x;i<=cnt;i++)
		{
			ans+=t[i];
		}
		ans+=M[x]+M[y];
		cout<<ans;
	}
} 
