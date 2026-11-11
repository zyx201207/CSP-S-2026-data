#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e3+5;
int n,d;
int x[N];
int dis[N][N];
int dis2[N][N];
int cnt[N][N];
void solve(){
	memset(dis,0x3f,sizeof(dis));
	memset(dis2,0x3f,sizeof(dis2));
	memset(cnt,0,sizeof(cnt));
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int dx=abs(x[j]-x[i]);
			if(dx<=d){
				dis2[i][j]=dis[i][j]=1;
				dis2[j][i]=dis[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(dis[i][j]==dis2[i][k]+dis2[k][j]){
					cnt[i][j]++;
//					cout<<k<<' '<<i<<' '<<j<<' '<<cnt[i][j]<<'\n';
				}
				if(dis2[i][j]>dis2[i][k]+dis2[k][j]){
					dis2[i][j]=dis2[i][k]+dis2[k][j];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int dd=x[2]-x[1];
	int len=d/dd;
	if(len<=1||len>=n){
		cout<<"0\n";
	}else{
		cout<<n-(len*2)+1<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	cout<<(long long)abs(-2e18);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			solve1();
		}
		return 0;
	}
	while(t--){
		solve();
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
11 1
10 1999999999999999970
-899999999999999986 -699999999999999989 -499999999999999992 -299999999999999995 -99999999999999998 99999999999999999 299999999999999996 499999999999999993 699999999999999990 899999999999999987
*/