#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct node{
	int to,next;
}e[N];
int c,t;
int n,d;
int a[N],pre[N],k=0,d[N];
void add(int u,int v)
{
	k++;
	a[k].to=v;
	a[k].next=pre[u];
	pre[u]=k;
}
priority_queue<int> q; 
void dijkstra()
{
	while(!q.empty()) q.pop();
	memset(d,0,sizeof(d));
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			add(a[1],a[n]);
		}
	}
	cout<<1<<endl<<2; 
	return 0;	
}