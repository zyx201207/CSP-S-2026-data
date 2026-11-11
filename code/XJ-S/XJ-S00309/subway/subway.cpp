#include<bits/stdc++.h>
using namespace std;
long long w[50005];
int h[600005],ne[2500005],e[2500005],idx;
long long ew[2500005],an[600005];
long long mem[1005][1005];
void add(int a,int b,long long ww)
{
	idx++;
	ne[idx]=h[a];
	h[a]=idx;
	e[idx]=b;
	ew[idx]=ww;
	return;
}
void dfs(int a)
{
	int i,j,k;
	long long sum=0;
	for(i=h[a];i!=0;i=ne[i])
	{
		if(an[e[i]]>an[a]+ew[i])
		{
			an[e[i]]=an[a]+ew[i];
			dfs(e[i]);
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long i,j,k,n,m,q,ans,sum,nu;
	cin>>n;
	cin>>n>>m>>q;
	cin>>q;
	for(i=1;i<=m;i++) cin>>w[i];
	nu=m;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			nu++;
			add(nu,a,t);
			add(a,nu,t);
			if(j>1)
			{
				add(nu,nu-1,0);
				add(nu-1,nu,0);
			}
		}
	}
	while(q--)
	{
		int a,b; 
		cin>>a>>b;
		if(mem[a][b]==0&&a!=b)
		{
			memset(an,0x3f3f3f,sizeof an);
			an[a]=0;
			dfs(a);
			for(i=1;i<=m;i++)
			{
				mem[a][i]=mem[i][a]=an[i];
			}
		}
		ans=mem[a][b]+w[a]+w[b];
		cout<<ans<<endl;
	}
	return 0;
}
