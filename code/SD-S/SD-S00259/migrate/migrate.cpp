#include<bits/stdc++.h>
#define int long long
#define N 310
using namespace std;
int c;
int T,n,d,a[N],dp[N][N],cnt,mn;
void solve (){
	cin>>n>>d;
	cnt=0;
	if (n<=3){
		cout<<"0\n";
		return ;
	}
	memset (dp,0,sizeof dp);
	for (int st=1; st<=n; st++){ //起点 
		mn=1;
		dp[st][0]=1;
		for (int i=st+1; i<=n; i++){ //终点
			while (a[i]>a[st]+d*mn){
				mn++;
			}
			if (mn==1){
				dp[i][0]=1;
			}
			for (int j=max (mn,2LL); j<=i-st; j++){ //枚举第二维 
				for (int k=i-j; k>=st && a[k]+d*j>=a[i]; k--){
					dp[i][j]+=dp[k][j-mn]; 
				}
			}
			cnt+=(dp[i][mn]==2);
		}
	}
	cout<<cnt<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while (T--){
		solve ();
	}
	return 0;
}
