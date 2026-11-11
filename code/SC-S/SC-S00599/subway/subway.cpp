#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
const int N = 5e5+5;
using namespace std;

struct node{
	int u,v;
};

vector<node>a[N];
int x[N],y[N];
int c,n,m,d,q;
int l1,rr;
ll s[N],dp[N];
ll mi=1e18;
ll solve(int l){
	for(auto i:a[l]){
		if(i.u==rr){
			mi=min(mi,dp[l]+i.v);
			continue;
		}
		if(dp[i.u]>=dp[l]+i.v){
			dp[i.u]=dp[l]+i.v;
			solve(i.u);
		}
	}
	return mi;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c >>n >>m >>d >>q;
	for(int i=1;i<=m;i++) cin >>s[i];
	for(int i=1;i<=n;i++){
		int num;cin >>num;
		for(int j=1;j<=num;j++){
			cin >>x[j] >>y[j];
			for(int k=1;k<j;k++){
				a[x[k]].push_back({x[j],y[j]+y[k]});
				a[x[j]].push_back({x[k],y[j]+y[k]});
			}
		}
	}
	while(q--){
		mi=1e18;
		for(int i=1;i<=m;i++) dp[i]=1e18;
		cin >>l1 >>rr;
		dp[l1]=0;
		cout <<s[l1]+solve(l1)+s[rr] <<endl;
	}
	return 0;
}
