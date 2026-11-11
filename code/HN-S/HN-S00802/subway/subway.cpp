#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[509],g[500009],x[100009],y[100009],T=1,tot=100000,v[1000][1000];
struct node{
	int a,t;
}w[509][20];
void dfs(int beg,int sum,int goal){
	if(beg==goal){
		tot=min(tot,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(v[i][j]==0||beg==w[i][j].a)
			{
				sum+=w[i][j].t;
				v[i][j]=1;
				dfs(w[i][j].a,sum,goal);
				sum-=w[i][j].t;
				v[i][j]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>g[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>w[i][j].a>>w[i][j].t;
		}
	}
	for(int T=1;T<=q;T++) 
	{
		cin>>x[T]>>y[T];
		tot=100000;
		int s=0;
		s+=g[x[T]]+g[y[T]];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++)
				if(w[i][j].a==x[T])
				{
					dfs(w[i][j].a,w[i][j].t,y[T]);
				}
		s+=tot;
		cout<<s<<endl;
	}
	
	return 0;
} 
