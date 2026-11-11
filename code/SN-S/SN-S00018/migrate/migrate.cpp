#include <bits/stdc++.h>
using namespace std;
long long INF = 4000000000000000020ll;
int IINF = 11451419;
int gr[310][310];
int dp[310][310][310];
long long a[501];
void check(){
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 0;i<n;++i) cin>>a[i];
	for(int i = 0;i<305;++i){
		for(int j = 0;j<305;++j) gr[i][j]=IINF;
	}
	for(int i = 0;i<n;++i) gr[i][i]=0;
	for(int i = 0;i<n;++i){
		for(int j = i+1;j<n;++j){
			if(i==j) continue;
			if(a[j]-a[i]<=m){
				gr[i][j]=1;
				gr[j][i]=1;
				dp[i][j][1]=1;
			}
		}
	}
	//floyd
	for(int k = 0;k<n;++k){
		for(int i = 0;i<n;++i){
			for(int j = 0;j<n;++j){
				gr[i][j]=min(gr[i][j],gr[i][k]+gr[k][j]);
			}
		}
	}
	int maxl = 0;
	for(int i = 0;i<n;++i){
		for(int j = i+1;j<n;++j){
			if(gr[i][j]==IINF) continue;
			maxl = max(maxl,gr[i][j]);
		}
	}
	for(int k = 2;k<=maxl;++k){
		for(int i = 0;i<n;++i){
			for(int j = i+1;j<n;++j){
				for(int mp = i+1;mp<j;++mp){
					if(a[j]-a[mp]<=m) dp[i][j][k]+=dp[i][mp][k-1];
				}
			}
		}	
	}
	int ans=0;
	for(int i = 0;i<n;++i){
		for(int j = i+1;j<n;++j){
			if(dp[i][j][gr[i][j]]==2) ++ans;
		}
	}
	cout << ans << '\n';
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			for(int k = 0;k<=maxl;++k){
				dp[i][j][k]=0;
			}
		}
	}
}

void check0(){
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 0;i<n;++i) cin>>a[i];
	long long d0=a[1]-a[0];
	int mcross=m/d0;
	long long ans=0;
	//统计跨了mc+1~2mc-1个的
//	cout << '*' << d0 << '*' << m  << '\n';
	for(int i = mcross+1;i<=min(2*mcross-1,n-1);++i){
		ans+=n-i;
	} 
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	if(c!=11&&c!=12) for(int i = 0;i<t;++i)check();
	else for(int i = 0;i<t;++i) check0();
	return 0;
} 
