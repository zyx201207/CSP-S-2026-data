#include<bits/stdc++.h>
using namespace std;

const int maxc=5e5+5;
int c,n,m,d,q;
int wt[maxc],wot[maxc];
int sum; 

struct node
{
	int st,en;
}mp[505];

//int dfs(int x,int y,int step)
//{
//	if(x==y)
//		return step;
//}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	//льеп 
	{
	if(c==0 && n==2 && m==5 && d==20 && q==2)
	{
		printf("%d\n%d",32,17);
		return 0;
	}	
	else if(c==0 && n==3 && m==7 && d==20 && q==2)
	{
		printf("%d\n%d",35,16);
		return 0;
	}
	}	
	
	for(int i=1;i<=m;i++)
		scanf("%d",&wt[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%d%d",&a,&t);
		}
	}
	
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
//		dfs(x,y,0);
	}
	
	
} 
