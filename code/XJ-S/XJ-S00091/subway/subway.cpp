#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,t;
};
int c,n,m,d,q,k,i,j,x,y;
vector <int> v[500005];
node s[500005];
int w[500005];
void dfs(int x1,int t)
{
	t=t+s[x1].t;
	if(x1==y)
	{
		cout<<t;
		return ;
	}
	for(i=0;i<v[x1].size();i++)
	{
		dfs(v[x1][i],t);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int A=0;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>s[i].a>>s[i].t; 
			if(A!=0)
			{
				v[A].push_back(s[i].a);
			}
			A=s[i].a; 
		}
	}
	for(i=1;i<=q;i++)
	{
		cin>>x>>y;
		dfs(x,w[x]+w[y]);
	}
	return 0;
}

