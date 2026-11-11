#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
#define ll long long
int c,n;
ll d,x[N],t[N];
int dp[N];
void solve(){
	scanf("%d%lld",&n,&d);
	ll mmin=LONG_LONG_MAX;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&x[i]);
		if(i>1) mmin=min(mmin,x[i]-x[i-1]);
	}
	if(n<=3 or x[n]-x[1]<=d or mmin>d){
		printf("0\n");
		return ;
	}
	ll res=0;
	for(int l=1;l+3<=n;l++){
		if(x[n]-x[l]<=d) break;
		for(int k=0;k<=n;k++) t[k]=0;
		dp[l]=0;
		t[0]++;
		int i=l+1,j=l;
		for(;i<=n;i++){
			if(x[i]-x[i-1]>d) break;
			while(j<i and x[j]<x[i]-d) t[dp[j]]--,j++;
			dp[i]=dp[j]+1;
			if(t[dp[j]]==2) res++;
			t[dp[i]]++;
		}
	}
	printf("%lld\n",res);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	scanf("%d%d",&c,&t);
	while(t--) solve();
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
