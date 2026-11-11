#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
const int M=305;
int c,t,n,d;
int a[N];
int dis[M][M];
int sum[M][M];
void solv(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(c<=6){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) sum[i][j]=dis[i][j]=0;
			if(i!=j&&abs(a[i]-a[j])<=d) sum[i][j]=dis[i][j]=1;
			if(i!=j&&abs(a[i]-a[j])>d) sum[i][j]=0,dis[i][j]=1e15;
		}
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(dis[i][j]>dis[i][k]+dis[k][j])
				dis[i][j]=dis[i][k]+dis[k][j],sum[i][j]=sum[i][k]*sum[k][j];
			else if(dis[i][j]==dis[i][k]+dis[k][j])
				sum[i][j]+=sum[i][k]*sum[k][j];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(sum[i][j]==2) ans++;
		cout<<ans/2<<"\n";
		return ;
	}
	if(c>=11&&c<=12){
		int len=a[2]-a[1],t=d/len;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(i+2*t-1<=n) ans++;
		cout<<ans<<"\n";
		return ;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
		solv();
	return 0;
}