#include<bits/stdc++.h>
using namespace std;
vector<long long>G[1000005];
long long dp[1000005][5];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		cout<<n/m-(n/m>1?1:0)<<"\n";
	}
	return 0;
}
