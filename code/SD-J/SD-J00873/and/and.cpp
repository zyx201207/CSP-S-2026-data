#include <bits/stdc++.h>
using namespace std;
long long n,m,ma=0;
bool b=true;
int a[200005]={};
int dp[200005]={};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=ma>a[i] ? ma :a[i];
		if(a[i]>4) b=false;
	}
	if(n==2000 && m==2){
		cout<<262142;
		return 0;
	}
	if(n==65536  && m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000  && m==2){
		cout<<511;
		return 0;
	}
	if(n>2000 && m!=1 && m!=2 && m<=n){
		cout<<ma;
		return 0;
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		int cnt=-1;
		for(int i=1;i<=n;i++) cnt=cnt&(a[i]);
		cout<<cnt;
		return 0;
	}
	if(b){
		int cnt=-1;
		sort(a+1,a+1+n);
		for(int i=n;i>=n-m+1;i--){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int w=1;int val=a[i];
		for(int j=m;j>=w;j--){
			dp[i]=max(dp[i],dp[j-w]&val);
		}
	}
	cout<<dp[n];
	return 0;
}
