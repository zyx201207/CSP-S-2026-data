#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6*2+200;
const int INF=1e18;
int c;
int dp[N],a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		int n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				dp[i]=dp[j]+1;
				if(dp[i]==2){
					cnt++;
					dp[i]=0;
				}
			}
		}
		cout<<cnt;
		for(int i=1;i<=n;i++){
			dp[i]=0;
		}
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/

