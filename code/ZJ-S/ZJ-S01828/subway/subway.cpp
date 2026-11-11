#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,q,d,L,R,b[510],w[510],l[510],t[510][51000],e[51000],f[510][510],a[510][51000];
struct xx
{
	int s,x;
};
void bfs(int x)
{
	int X=x;
	queue<xx> q;
	q.push(xx{x,0});
	while(q.size())
	{
		int s=q.front().s;
		int x=q.front().x;
		q.pop();
		for(int i=1;i<=l[x];i++)
		if(b[a[x][i]]==0)
		{
			cout<<1145134;
			f[X][a[x][i]]=s+t[e[a[x][i]]][i]+t[e[a[x][i]]][i];
			q.push(xx{a[x][i],f[X][a[x][i]]}),b[a[x][i]]=1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		for(int j=1;j<=l[i];j++) cin>>a[i][j]>>t[i][j],e[a[i][j]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++) b[j]=0;
		b[i]=1;
		bfs(i);
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++) cout<<f[i][j]<<' ';
		cout<<'\n';
	}
	
	while(q--)
	{
		cin>>L>>R;
		cout<<f[L][R]+w[L]+w[R]<<'\n';
	}
	return 0;
}

