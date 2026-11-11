//migrate
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+5;
const int inf=1e9;
int T,c;
void solve(){
	int dis[N][N];
	int cnt[N][N];
	int a[N];
	int n,d;
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
			cnt[i][j]=0;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]+d>=a[j]){
				dis[i][j]=(int)abs(a[i]-a[j]);
				dis[j][i]=(int)abs(a[i]-a[j]);
			}
				
		}
		/*t j=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
		//cout<<"j:"<<j<<"\n";
		for(;j>=i;j--){
			dis[i][j]=abs(a[i]-a[j]);
		}*/
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]!=inf && dis[k][j]!=inf)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=i+1;k<j;k++)
				if(dis[i][j]==dis[i][k]+dis[k][j] && dis[i][j]!=inf)
					cnt[i][j]++;
					
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)
				ans++;	 
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
 	cin>>c>>T;
 	while(T--){
 		solve();	
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/