#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,sum[N];
bool check(int len){
	for(int i=len;i<=n;i++){
		if(a[i]*len<=sum[i]-sum[i-len]+m) return 1;
	}
	return 0;
}
int f(int l,int r){
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	cout<<f(1,n);
	return 0;
} 