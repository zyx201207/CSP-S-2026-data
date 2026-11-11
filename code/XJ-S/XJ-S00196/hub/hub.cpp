#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
const int N=2e6+5;
int fa[N];
int e[N],ne[N],idx,h[N];
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int p=0;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
			if(u+1==v) p=1;
			add(u,v);
			add(v,u);
		}
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f!=fa[j]) cnt++;
				cnt--;
				if(cnt>=3) continue;
			}
		}
		cout<<p<<endl;
	}
	return 0;
 } 
