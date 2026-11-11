

#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
long long c,T,x[N],a[N][N],dp[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		long long n,d,ans=0;
		cin>>n>>d;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				a[i][j] = x[j] - x[i] ;
			}
		}
		dp[1]=1;
		for(int i=1;i<=n;i++){
			for(int j=n;j>i;j--){
				if(a[i][j]<=d)	dp[j]+=dp[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i]>=2&&i>=4){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

