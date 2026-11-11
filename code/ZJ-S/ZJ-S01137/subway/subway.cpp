#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k[505],a[505][200010],t[505][200010],ans;
struct node{
	long long x,ti,h;
	int s;
};
node qu[500010],st,ed;

long long f=1,b=0;

void bfs(node st,node ed)
{
	qu[++b]=st;
	while(f<=b)
	{
		node u=qu[f++];
		if(u.x==ed.x && u.s==ed.s)
		{
			if(u.ti<ans)ans=u.ti;
			continue;
		}
		if(u.s==1)
		{
			node v;
			v=u;
			v.ti=u.ti+w[u.x];
			v.s=2;
			qu[++b]=v;
		}
		if(u.s==2)
		{
			if(u.x==ed.x)
			{
				node v;
				v=u;
				v.s=1;
				v.ti+=w[u.x];
				qu[++b]=v;
			}
			else
			{
				//huan
				for(int i=1;i<=n;i++)
				{
					if(t[i][u.x])
					{
						node v;
						v=u;
						v.h=i;
						v.s=2;
						qu[++b]=v;
					}
				}
				
				for(int j=1;j<=k[u.h];j++)
				{
					node v;
					v=u;
					v.s=2;
					v.ti=v.ti+t[v.h][v.x]+t[v.h][a[v.h][j]];
					v.x=a[v.h][j];
					qu[++b]=v;
				}
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int v=1;v<=m;v++)
	{
		cin>>w[v];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	for(int r=1;r<=q;r++)
	{
		ans=0x3f3f3f;
		long long x,y,cnt=0;
		cin>>x>>y;
		st.x=x;
		st.ti=0;
		st.s=1;
		ed.x=y;
		ed.s=1;
		f=1;
		b=0;
		bfs(st,ed);
		cout<<ans<<endl;
	}
	return 0;
}
