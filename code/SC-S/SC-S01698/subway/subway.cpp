#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const long long N=1e6+5,B=131;
ll n,m,k,t,sum=0,ans=0;
ll a[505],dp[3005][3005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,d; 
	cin>>c>>n>>m>>d>>t;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		cin>>a[i];
		dp[i][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,w;
			cin>>y>>w;
			dp[y][m+i]=dp[m+i][y]=w;//cout<<j<<" "<<2*x<<"\\";
		}
	}
		
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=i+1;j<=n+m;j++){
				if(dp[i][k]+dp[k][j]<dp[i][j]){
					dp[i][j]=dp[i][k]+dp[k][j]; 
				}
			}
		}
	}
	while(t--){
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		cout<<dp[x][y]+a[x]+a[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

-

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16

	 /\_/\   ?
	( o o ) 
   \/    \


*/