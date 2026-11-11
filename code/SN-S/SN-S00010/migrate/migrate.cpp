#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+10;
struct Node
{
	int x,nnext,next[501],v,w;
	Node(){for(int i=0;i<501;i++)next[i]=0;nnext=v=w=0;}
};
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,ans=0;
		Node node[501];
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>node[i].x;
			for(int j=i;j>1&&node[i].x-node[j].x<=d;j--)
				node[j].next[node[j].nnext++]=i;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)node[j].v=node[j].w=0;
			for(int j=i;j<n;j++)
			{
				for(int cur=0;cur<node[j].nnext;cur++)
				{
					int p=node[j].next[cur];
					if(!node[p].v)
					{
						node[p].v=node[cur].v+1;
						node[p].w=node[cur].w;
					}
					else 
					{
						if(node[p].v>node[cur].v+1)
						{
							node[p].v=node[cur].v+1;
							node[p].w=node[cur].w;
						}
						else if(node[p].v==node[cur].v+1)
							node[p].w++;
					}
				}
			}
			for(int j=i;j<=n;j++)if(node[j].w==2)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
