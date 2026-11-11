#include <bits/stdc++.h>
#define int long long
using namespace std;
int Task,t;
void solve(){
	int n;
	long long d;
	cin>>n>>d;
	vector<long long>x(n+1);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	vector<int>f(n+1,0);
	vector<int>L(n+1,0);
	vector<int>R(n+1,0);
	vector<int>sumf(n+1,0);
	int l=1,r=0;
	L[1]=1,R[1]=0;
	for(int i=2;i<n;i++){
		if(x[i]-x[i-1]>d){
			f[i]=0;
			L[i]=i,R[i]=i;
		}else{
			while(x[i]-x[l]>d) l++;
			while(x[i+1]-x[r+1]>d&&r+1<i) r++; 
			L[i]=l;
			R[i]=r;
			f[i]=sumf[r]-sumf[l-1]+(r-l+1);
			
			
		}
		sumf[i]=sumf[i-1]+f[i];
	}
	while(x[n]-x[l]>d){
		l++;
	}
	L[n]=l;
	R[n]=n-1;
	f[n]=sumf[n-1]-sumf[l-1]+n-l;
	sumf[n]=sumf[n-1]+f[n];/*
	for(int i=1;i<=n;i++){
		cout<<f[i];
	}puts("");*/
	vector<int> dp(n+1,0);
	vector<int> sumdp(n+1,0);
	vector<int> ans(n+1,0);
	long long sumans=0;
	for(int i=2;i<=n;i++){
		if(x[i]-x[i-1]>d){
			dp[i]=0;
		}else{
			dp[i]+=sumdp[R[i]]-sumdp[L[i]-1];
			ans[i]+=sumdp[i-1]-sumdp[L[i]-1];
			int pr=R[L[i]+1],pl=L[L[i]+1];
			if(L[i]+1<=R[i]&&pr>=pl){
				dp[i]+=sumf[pr]-sumf[pl-1]+(pr-pl+1);
			}
			if(L[i]+1<i&&pr>=pl){
				ans[i]+=sumf[pr]-sumf[pl-1]+(pr-pl+1);
			}
		}
		sumans+=ans[i];
		sumdp[i]=sumdp[i-1]+dp[i];
	}
	cout<<sumans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>Task>>t;
	while(t--){
		solve();
	}
	return 0;
}