#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,M=305;
int a[N];
int n,d; 
int dis[M][M],a1[M][M];
void work1()
{
	for(int i=1;i<=n;i++)
	{
		int last=i,num=1;
		for(int j=i+1;j<=n;j++) 
		{
			if(a[j]-a[last]<=d) dis[i][j]=num;
			else 
			{
				if(a[j]-a[j-1]>d) break;
				else{num++,last=j-1; dis[i][j]=num;}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j+i<=n;j++)
	{
		if(dis[j][i+j]==1) a1[j][i+j]=1;
		else for(int k=j+1;k<i+j;k++){
			if(dis[j][k]>1) break;
			if(dis[j][i+j]&&dis[j][i+j]==dis[j][k]+dis[k][i+j]) a1[j][i+j]+=a1[j][k]*a1[k][i+j];
		}
		a1[j][i+j]=min(a1[j][i+j],10ll);
		if(a1[j][i+j]==2) ans++;
	}
	cout <<ans <<'\n';
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=0,a1[i][j]=0;
}
void work2()
{
	int x=a[2]-a[1];
	int num=d/x;
	if(num<2) cout <<"0\n";
	else cout <<max(n-num-num+1,0ll) <<'\n';
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int NUM,_; cin >>NUM >>_;
	while(_--)
	{
		cin >>n >>d;
		for(int i=1;i<=n;i++) cin >>a[i];
		if(n<=300) work1();
		else work2();
	}
	return 0;
}
