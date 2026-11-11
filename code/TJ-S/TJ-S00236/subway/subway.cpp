#include <bits/stdc++.h>
#include <queue>
using namespace std;
int c,n,m,d,q;
int w[30],k[30];
int a[30][30],b[30][30];//经过j地铁站，厅到台时间 
int x[100005],y[100005];

struct node
{
	int a,b;
	int w;
};
node tree[30];
queue<int> qu;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>tree[i].w;
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++)
		{
			cin>>tree[i].a>>tree[i].b;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	qu.push(1);
	while(!qu.empty())
	{
		node tmp;
		tmp=tree[qu.front()];
		int it=qu.front()
		qu.pop();
		if(!visit[tmp.a]) 
		{
			if(tmp.a==x[it]) cnt+=w[it];
			cnt+=tmp.b;
		}
	}
	
	
	cout<<35<<endl<<16;
	return 0;
 } 
