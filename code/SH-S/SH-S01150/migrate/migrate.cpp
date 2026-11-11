#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000009],r[2000009],f[5009][5009],dp[5009][5009];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		r[i]=r[i-1];
		while(x[r[i]+1]-x[i]<=d&&r[i]<n)r[i]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=r[i];j++){
			f[i][j]=1;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	
	
	
	
	
	
	
	return 0;
} 
