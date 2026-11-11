#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
};
struct node2
{
	int x,y,id;
};
bool cmp(node2 x,node2 y)
{
	if(x.x==y.x)
	{
		return x.y<y.y;
	}
	return x.x<y.x;
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
int C,n,m,D,q,w[500005],k[505],T;
// vector<int> a[505],t[505];
vector<node> v[500505];
node2 p[100005];
long long ans[100005];
long long d[500505];
//bool vis[500505];
void dijk(int st)
{
	for(int i = 0;i <= T;i++)
	{
		d[i]=1e18;
//		vis[i]=0;
	}
	d[st]=0;//int mini=st;vis[st]=1;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> Q;
	Q.push({0,st});
	for(int i = 1;i < T;i++)
	{
		// cout<<mini<<endl;
		int cc=Q.top().second;Q.pop();
		for(int j = 0;j < v[cc].size();j++)
		{
			int x=v[cc][j].x,y=v[cc][j].y;
			if(d[x]>d[cc]+y)
			{
				d[x]=d[cc]+y;
				Q.push({d[x],x});
			}
		}
		// mini=0;
		// for(int j = 1;j <= T;j++)
		// {
		// 	if(!vis[j]&&d[mini]>d[j])
		// 	{
		// 		mini=j;
		// 	}
		// }
		// vis[mini]=1;
	}
}
int main()
{
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();n=read();m=read();D=read();q=read();T=n+m;
	for(int i = 1;i <= m;i++)w[i]=read();
	for(int i = 1;i <= n;i++)
	{
		k[i]=read();
		for(int j = 0;j < k[i];j++)
		{
			int aa=read(),tt=read();
			v[aa].push_back(node{m+i,tt});
			v[m+i].push_back(node{aa,tt});
			// a[i].push_back(aa);
			// t[i].push_back(tt);
		}
	}
	// for(int i = 1;i <= T;i++)
	// {
	// 	cout<<i<<':'<<endl;
	// 	for(int j = 0;j < v[i].size();j++)
	// 	{
	// 		cout<<v[i][j].x<<' '<<v[i][j].y<<endl;
	// 	}
	// }
	for(int i = 1;i <= q;i++)
	{
		p[i]={read(),read(),i};
		// cout<<i<<':'<<endl;
		// ans[i]=dijk(p[i].x,p[i].y)+w[p[i].x]+w[p[i].y];
		if(p[i].x>p[i].y)swap(p[i].x,p[i].y);
	}
	sort(p+1,p+q+1,cmp);
	for(int i = 1;i <= q;)
	{
		// cout<<i<<endl;
		dijk(p[i].x);
		while(i<=q&&p[i+1].x==p[i].x)
		{
			ans[p[i].id]=d[p[i].y]+w[p[i].x]+w[p[i].y];
			i++;
		}
		ans[p[i].id]=d[p[i].y]+w[p[i].x]+w[p[i].y];
		i++;
	}
	for(int i = 1;i <= q;i++)
	{
		write(ans[i]);
		putchar('\n');
	}
	return 0;
}