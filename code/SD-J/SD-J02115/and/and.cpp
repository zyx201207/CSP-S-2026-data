#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=2e4+10;
int n,m;
int a[N];
int sum[N],dp[M][M];
int maxx,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000&&n<=N){
		if(m==n-1){ 
			long long a2,b;
			for(int i=1;i<=n-1;i++){
				a2&=a[i];
			}
			for(int i=2;i<=n;i++){
				b&=a[i];
			}
			cout<<max(a2,b);
			return 0;
		}
		else{
			for(int i=1;i<=n;i++) {
				dp[i][1]=a[i];
			}
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				for(int j=2;j<=m;j++){
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
				}
			}
			cout<<dp[n][m];
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]&a[i];
		}
		cout<<sum[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=a[i]&a[j];
				maxx=max(maxx,cnt);
			}			
		}
		cout<<maxx;
		return 0;
	}	
	for(int i=1;i<=n;i++) {
		dp[i][1]=a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
