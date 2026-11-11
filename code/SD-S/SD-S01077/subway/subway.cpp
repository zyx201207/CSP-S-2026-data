#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N],l,r,k,cnt=1;
long long e[N],ne[600],h[600],idx=1,wi[N];
long long a,t;
typedef pair<int,int>PII;
void add(int a,int b,int c)
{
	e[idx]=b,wi[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int dist[N];
bool st[N];
int f(int l,int r)
{
	memset(dist,0x3f,sizeof dist);
	dist[l]=wi[l];
	st[l]=true;
	priority_queue<PII,vector<PII>,greater<PII> >heap;
	heap.push({l,dist[l]});
	for(int i=h[l];i!=-1;i=ne[i])
	{
		PII k=heap.top();	
		int j=e[i];
		int ver=k.first,distance=k.second;
		heap.pop();
		if(dist[ver]+wi[j]<dist[j] && st[j]==false)
		{
			dist[j]=dist[ver]+wi[j];
			st[j]=true;
			heap.push({j,dist[j]});
		}
	}
	return dist[r];
}
int main()
{
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			add(i,a,t);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		int op=f(l,r)+w[l]+w[r];
		cout<<op<<endl;
	}
	return 0;
}
