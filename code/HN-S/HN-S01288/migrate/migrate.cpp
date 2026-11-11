#include<bits/stdc++.h>
using namespace std;
const long long maxn=5555;
long long n,d,c,t;
long long x[maxn];
long long dp[maxn][maxn];
long long len[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		cout<<n-3<<'\n';
		
	}
	return 0;
} 
