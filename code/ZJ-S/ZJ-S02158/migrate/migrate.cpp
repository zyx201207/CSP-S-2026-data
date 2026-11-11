#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000003],pre[2000004],las[2000004];
vector<long long> v[2000044];
int y[5003][5003],coun[5002][5003];bool vis[5004];
void dfs1(int fa,int x,int sum,int ori)
{
	for(auto k:v[x])
	{
		y[k][ori]=min(y[k][ori],sum);
		y[ori][k]=y[k][ori];
		if(k!=fa&&!vis[k])
		{
			vis[k]=1;
			dfs1(x,k,sum+1,ori);
		}
		
	}
	return ;
}
void dfs2(int fa,int x,int sum,int ori)
{
	
	for(auto k:v[x])
	{
		if(sum==y[ori][k])
		{
			coun[ori][x]++;
			coun[x][ori]++;
		}
		if(k!=fa)
		{
		//	vis[k]=1;
			dfs2(x,k,sum+1,ori);
		}
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
 	for(int i=1;i<=5000;i++)
	 {
	 	for(int j=1;j<=5000;j++)
	 		y[i][j]=1e18;
	 }
	cin>>c>>t;
	while(t--)
	{
	
		cin>>n;
		cin>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
//		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			pre[i]=(upper_bound(a+1,a+1+n,a[i]+d)-a)-i-1;
			for(int j=i;j<=i+pre[i];j++)
			{
				v[i].push_back(j);
				v[j].push_back(i);
			}
			las[i]=i-(lower_bound(a+1,a+1+n,a[i]-d)-a);
		}
//		for(int i=1;i<=n;i++)
//			dfs1(-1,i,1,i),memset(vis,0,sizeof vis);
//			
//		for(int i=1;i<=n;i++)
//			dfs1(-1,i,1,i),memset(vis,0,sizeof vis);
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//				cout<<y[i][j]<<" ";
//			cout<<'\n';
//		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//				cout<<coun[i][j]<<" ";
//			cout<<'\n';
//		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<las[i]<<" "<<pre[i]<<"\n";
//		}
		int ans=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+2;j<=n;j++)
			{
				long long k=j-i-1;
					if(min((j-i),las[j])+min(pre[i],(j-i))-k==2)
					{
						ans++;
						//cout<<i<<" "<<j<<"\n";
					}
			}
		}
		cout<<ans<<"\n";
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