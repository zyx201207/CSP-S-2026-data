#include<bits/stdc++.h>
using namespace std;
long long int c,T; 
long long int a[200005];
long long int vis[200005];
long long int sum[200005];
long long int cnt=100000000,cnt1=0;
void dfs(long long int t,long long int x,long long int y,long long int k)
{
	sum[1]=a[t];
	if(sum[k]==a[x])
	{
		if(k<cnt)
		{
			cnt1=1;
			cnt=k;
			return;
		}
		if(k==cnt) cnt1+=1;
		//cout<<cnt1<<" "<<sum[1]<<" "<<cnt2<<endl;
		//cout<<k<<" "<<cnt1<<endl;
		return ;
	}
	for(long long int i=t;i<=x;i++)
	{
		if(vis[i]==0 && a[i]>sum[k] && a[i]-sum[k]<=y)
		{
			sum[k+1]=a[i];
			vis[i]=1;
			dfs(t,x,y,k+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	long long int n,d;
	while(T--)
	{
		long long int f=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int j=1;j<=n;j++)
		{
			for(int i=j+1;i<=n;i++)
			{
				cnt1=0;
				cnt=100000000;
				memset(vis,0,sizeof(vis));
				memset(sum,0,sizeof(sum));
				dfs(j,i,d,1);
				//cout<<"x";
				if(cnt1==2) f+=1;
			}
		}
		cout<<f<<endl;
	}
	return 0;
}
