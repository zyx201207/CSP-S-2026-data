#include<bits/stdc++.h>
using namespace std;
const long long M=100000050;
const long long N=50050;
long long n,m,b[M],c=0;
long long ans=0,t=0,q;

struct E{
	long long  x,y;
};
E a[N];

void dfs(int u)
{
	if(u==m+1){
			for(int i=1;i<=n;i++)	b[i]=0;
			for(int j=1;j<=n;j++)
			{
				 q=a[j].x+a[j].y;
				
				b[q]++;
				c=max(c,b[q]);
			}
			/*
			for(int i=1;i<=n;i++)	printf("%d %d ",a[i].x,a[i].y);
			cout<<endl;
			for(int i=1;i<=M;i++){
				if(b[i]!=0){
					printf("%d ",i);c=max(c,b[i]);
				}
			}
			cout<<"c="<<c<<endl;*/
			return;
		}
	
	for(int i=1;i<=n;i++)
	{
		a[i].y++;
		dfs(u+1);
		
		a[i].y--;
		
	}
	
	
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(a,-1e9,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
	}
	for(int i=1;i<=n;i++)	a[i].y=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
				if(a[j].x<a[i].x)	{
				int q;
				q=a[i].x;
				a[i].x=a[j].x;
				a[j].x=q;
			}
		}
		
	}
	
	dfs(1);
	
/*	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[a[j]]++;
			c=max(b[a[j]],c);
		}
		
	}
	for(int i=1;i<=n;i++)	printf("%d ",b[i]);
	cout<<endl;
	cout<<c;*/
	t=a[2].x-a[1].x;
	printf("%d",(m/t)+1);
	return 0;
}
