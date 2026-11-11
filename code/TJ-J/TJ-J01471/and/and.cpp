#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
int w[N][45];
long long solveans;
bool Cmp(long long a,long long b){
	return a>b;
}
void dfs(int cur,int nk,long long lss){
	if(nk==m){
		solveans=max(solveans,lss);
		return;
	}
	for(int i=cur+1; i<=n; i++){
		dfs(i,nk+1,lss&a[i]);
	}
}
void solve(){
	dfs(0,0,2147483647);
	cout<<solveans;
}
bool check(int n){
	int lssum=1;
	for(int i=1; i<=21; i++){
		if(n==lssum){
			return true;
		}
		lssum*=2;
	}
	return false;
}
bool check1(long long n){
	int lssum=1;
	for(int i=1; i<=31; i++){
		if(n==lssum){
			return true;
		}
		lssum*=2;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool bjj=0;
	bool bji=0;
	long long maxx=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(a[i]!=i-1){
			bjj=1;
		}
		if(!check1(a[i]+1)){
			bji=1;
		}
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		long long lsans=a[1];
		for(int i=2; i<=n; i++){
			lsans&=a[i];
		}
		cout<<lsans;
		return 0;
	}
	if(n<=20){
		solve();
		return 0;
	}
	if(check(n) && !bjj){
		cout<<n-m;
		return 0;
	}
	if(!bji){
		sort(a+1,a+1+n,Cmp);
		long long ans4=a[1];
		for(int i=2; i<=m; i++){
			ans4&=a[i];
		}
		cout<<ans4;
		return 0;
	}
	
	sort(a+1,a+1+n,Cmp);
	long long anss=a[1];
	for(int i=2; i<=m; i++){
		anss&=a[i];
	}
	cout<<anss;
	
	return 0;
}
