#include<bits/stdc++.h>
using namespace std;
//#define int long long 
int c,n,m,d,q,w[500050],a,t,startnd,endnd,k;
struct node{
	int xl;//xianlu
	int bz;//juli
	friend bool  operator< (node x,node y)
{
	return x.bz>y.bz;
};
}nd;
vector<node>sby[500050],snd[500050],sbcc;
vector<int>smin[500050];
int vis[500050],tn[500050];
bool visub[500050];

priority_queue<node,vector<node>>qu;
void bfs(int nownd)
{
	nd.xl=nownd;
	nd.bz=0;
	qu.push(nd);
	while(1)
	{
		if(qu.top().xl==endnd)break;
		for(node x:snd[qu.top().xl])
		{
			//cout<<1<<endl;
			if(visub[x.xl]==1)continue;
			for(node v:sby[x.xl])
			{
				nd.xl=v.xl;
				nd.bz=v.bz+x.bz+qu.top().bz;
				if(vis[nd.xl]>nd.bz)
				{
					vis[nd.xl]=nd.bz;
					sbcc.push_back(nd);
					//cout<<2<<endl;
				}
			}
			visub[x.xl]=1;
		}
		qu.pop();
		//cout<<3<<endl;
		for(node i:sbcc)qu.push(i);
		sbcc.clear();
	}
	return;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int qqq=q;
	q=9999999;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>nd.xl>>nd.bz;
			sby[i].push_back(nd);
			node nod;
			nod.xl=i;
			nod.bz=nd.bz;
			snd[nd.xl].push_back(nod);
		}
	}
	for(int i=1;i<=qqq;i++)
	{
		memset(vis,0x3f,sizeof(vis));
		memset(visub,0,sizeof(visub));
		cin>>startnd>>endnd;
		bfs(startnd);
		cout<<qu.top().bz+w[startnd]+w[endnd]<<endl;
		q--;
	}
	return 0;
}
//ccf 18 size already
//this is too difficult
//give me 60 point please
//or i might be Away From Oi
//i'm really baoli now

