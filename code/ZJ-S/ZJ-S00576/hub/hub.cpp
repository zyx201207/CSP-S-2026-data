#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,t;
int n,k;
int fa[N];
int cnt=0;
int find(int x,int y)
{
	if(fa[x]==fa[y]) return fa[x];
	fa[x]=find(fa[x],fa[y]);
	return fa[x];
}
int poss(int m)
{
	int sum=0;
	int js=1;
	while(js<=m)
	{
		sum++;
		js*=2;
	}
	return sum;
}
void run()
{
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		if(v-u==1) cnt++;
		fa[u]=find(u,v);
		fa[v]=find(u,v);
	}
	if(cnt==n-1)
	{
		if((n-1)%(k*2)==0)
		{
			cout<<(n-1)/(k*2)<<"\n";
		}else{
			cout<<(n-1)/(k*2)+1<<"\n";
		}
		return ;
	}else{
		int a=1;
		int dis=0;
		while(a<=n)
		{
			a*=2;
			dis++;
		}
		if(a-1==n)
		{
			if(k==1)
			{
				cout<<dis-1<<"\n";
				return ;
			}else{
				int pp=poss(k);
				cout<<dis-pp<<"\n";
				return ;
			}
		}else{
			if(k==1)
			{
				cout<<dis-1<<"\n";
				return ;
			}else{
				int pp=poss(k);
				cout<<dis-pp-1<<"\n";
				return ;
			}
		}
	}
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		run();
	}
	return 0;
}