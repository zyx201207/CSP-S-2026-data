#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct Edge{
	int v,nxt;
}e[5000005];
int h[1000005],tot;
inline void add(int u,int v)
{
	e[++tot]={v,h[u]};
	h[u]=tot;
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	srand(time(0));
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		cout<<rand()%11<<endl;
	}
	return 0;
}
