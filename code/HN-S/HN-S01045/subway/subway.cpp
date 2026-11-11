#include<bits/stdc++.h>
using namespace std;

struct t
{
	int e,len;
};

int cc,n,m,d,q,x,num,len,b,e,k;
vector<t> line[1500010];
int a[1500010];
bool vis[1500010];

void in(int &x){
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
}
void out(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) out(x/10);
	putchar(x%10+'0');
}

void dij()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qu;
	pair<int,int> p;
	memset(a,0x3f,sizeof(a));
	memset(vis,0,sizeof(vis));
	a[b]=0; 
	qu.push({b,0});
	vis[b]=1;
	while(!qu.empty())
	{
		p=qu.top();
		qu.pop();
		int u=p.first;
		for(int i=0;i<line[u].size();i++)
		{
			int v=line[u][i].e,lth=line[u][i].len;
			if(vis[v])
			{
				if(a[u]+lth<a[v]) 
				{
					a[v]=a[u]+lth;
					qu.push({v,a[v]});
				}
				continue;
			}
			vis[v]=1;
			a[v]=a[u]+lth;
			qu.push({v,a[v]});
		}
	}
	out(a[e]),putchar('\n');
}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	in(cc),in(n),in(m),in(d),in(q);
	num=m;
	for(int i=1;i<=m;i++)
	{
		in(len);
		line[i].push_back({++num,len});
		line[num].push_back({i,len});
	}
	for(int i=1;i<=n;i++)
	{
		in(k);
		for(int j=1;j<=k;j++)
		{
			in(e),in(len);
			line[++num].push_back({e,len});
			line[e].push_back({num,len});
		}
	}
	for(int i=1;i<=num;i++)
	{
		for(int j=0;j<line[i].size();j++) cout<<line[i][j].e<<' '<<line[i][j].len<<"  ";
		cout<<endl;
	}
	while(q--)
	{
		in(b),in(e);
		dij();
	}
	return 0;
}

