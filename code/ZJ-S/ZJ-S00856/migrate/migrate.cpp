#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,t,n,d,num[5010][5010],ar[5010][5010];//ar cishu,num fangshishu
long long a[N];
void init()
{
	memset(ar,0,sizeof ar);
	memset(num,0,sizeof num);
}
void solve()
{
	scanf("%d%d",&n,&d);
	init();
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++) ar[i][j]=1,num[i][j]=1;
	for(int i=1;i<=n;i++)
		for(int k=i+1;k<=n;k++)
		{
			if(!ar[i][k]) break;
			for(int j=k+1;j<=n;j++)
			{
				if(!ar[k][j]) break;
				if(!ar[i][j]) ar[i][j]=2,num[i][j]=num[i][k]*num[k][j];
				else if(ar[i][j]>=ar[i][k]+ar[k][j]) 
					ar[i][j]=ar[i][k]+ar[k][j],num[i][j]+=num[i][k]*num[k][j];
			}
		}
	int ans=0;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(num[i][j]==2) ans++;
	printf("%d",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
		solve();
	return 0;
}


