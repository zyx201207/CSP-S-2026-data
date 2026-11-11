#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+20;
long long a[N];
long long sum[N];
long long n,m;
long long l,r;
long long mid;
long long maxn=-1e9;
//long long dp[N][N];//dp[i][j]表示i次操作的水晶数 
bool check(int x){
	//判断最大的能量水晶能不能到达
	long long cnt=a[x]*x-sum[x];
	if(cnt>m){
		return false;
	}else if(cnt<=m){
		return true;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		long long x;
		cin>>x;
		a[i]=x;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	l=0,r=n;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			maxn=max(maxn,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<maxn<<'\n';
	return 0;
}
