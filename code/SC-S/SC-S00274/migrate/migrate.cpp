#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5010;
int c,t,n,sum,flag;
LL a[N],g[N],d;
void dfs(int len,int x,int y,int mlen)
{
	if(len>mlen||flag) return;
	if(sum>2) {flag=1;return;}
	if(x==y)
	{
		sum++;
		return;
	}
	for(int i=x+1;i<=g[x]&&i<=y;i++) dfs(len+1,i,y,mlen);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		int r=1,ans=0;
		for(int i=1;i<=n;i++)
		{
			while(r<n&&a[r+1]-a[i]<=d) r++;
			g[i]=r;
//			cout<<g[i]<<" ";
		}
//		cout<<endl;
		for(int i=1;i<=n;)
		{
			r=i; while(r<=n&&g[r]!=r) r++;
			for(int k=i;k<=r;k++)
			{
				for(int j=k+1;j<=r;j++)
				{
					int mlen=2,ri=k;
					while(g[ri]<j) ri=g[ri],mlen++;
					sum=flag=0,dfs(1,k,j,mlen);
//					cout<<k<<" "<<j<<" "<<mlen<<" "<<flag<<" "<<sum<<endl;
					if(!flag&&sum==2) ans++;
				}
			}
			i=r+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/