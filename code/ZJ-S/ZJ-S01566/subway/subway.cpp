#include<bits/stdc++.h>
using namespace std;
const int M=1e6+3;
#define int long long
int c,n,m,d,q;
struct node
{
	long long w,v;
	bool operator <(const node&other) const
	{
		return w>other.w;
	}
};
vector<node>a[M];
int dis[M];
int di(int xx,int yy)
{

	
	memset(dis,0x7f,sizeof(dis));
	dis[xx]=0;
	priority_queue<node>q;
	q.push({0,xx});
	while(!q.empty())
	{
		node j=q.top();
		q.pop();
		int u=j.v,w1=j.w;
		if(u==yy)return w1;
		for(node k:a[u])
		{
			int v=k.v,w2=k.w;
			if(dis[v]<dis[u])continue;
			if(v>m)
			{
				q.push({w2+w1,v});
			}
	         else if(dis[v]>w2+w1)
			{
				dis[v]=w2+w1;
				q.push({w2+w1,v});
			}
		}
	}
    	return -1;
}
int32_t main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;	
	int uy;
	int w[m+1];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		uy=m+i;
		a[uy].push_back({w[i],i});
		a[i].push_back({w[i],uy});
	}
	for(int id=1;id<=n;id++)
	{
		int k;
		cin>>k;
		//int hjhjhjhj=0;
		 int gh[k],gj[k];
		for(int j=0;j<k;j++)
		{
		   cin>>gh[j]>>gj[j];
		   //uy=m+gh;
		   //int jk=i+n+1;
		    // a[gh].push_back({jk,0});
		   //a[gh].push_back({gj+w[i]+w[gh],i});
	       //a[i].push_back({gj+w[i]+w[gh],gh});
		}
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				if(i==j)continue;
				int mk=gh[j]+m,ml=gh[i]+m;
				a[mk].push_back({gj[i]+gj[j],ml});
				a[mk].push_back({gj[i]+gj[j],ml});
			}
		}
	
	}
	for(int i=1;i<=q;i++)
	{

		int x,y;
		cin>>x>>y;
		cout<<di(x,y)<<endl;

		
	}
	return 0;
}
//1 1 2 4
//0 5 7 6
//1->2  5+ 