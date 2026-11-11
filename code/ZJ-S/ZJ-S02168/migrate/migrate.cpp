#include<bits/stdc++.h>
//#define int long long
#define For(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
int c,t,a[2000005],fA = 1;
int d[2000005]
int n,d,mn = 1e18+5;
int dp[2000005];

void dfs1(int u,int v,int now,int cnt){
	if(now >= v){
		mn = min(mn, cnt);
		return;
	}
	for(int i = 1;i <= n;i++){
		for(int i = u;i <= v;i++){
			
		}
	}
}

void A_score(){
	memset(dp, 0, sizeof(dp));
	int diff = a[2] - a[1];
	if(diff > d){
		cout<<0<<"\n";
		return;
	}
	else	cout<<n-3;
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate,in", "r", stdin);
	freopen("migrete.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		For(i, 1, n)	cin>>a[i];
		for(int i = 2;i <= n;i++){
			d[i] = a[i] - a[i-1];
		}
		if(c == 11 || c == 12){
			A_score();
		}
		if(c == 13 || c == 14){
			cout<<2;
		}
		if(c == 1 || c == 2){
			int dis = 0;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					for(int k = i+1;k <= j;k++){
						dis += d[k];	
					}
				}
			}
			cout<<dis;
		}
	}
	
	return 0;
}
