#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+500;
int a[MAXN],sum[MAXN];int n, m;int f;
bool check(int x){
	for(int i=x;i<=n;i++){
		int d=a[i]*(x-1)-sum[i-1]+sum[i-x];
		if(d<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1, r=n, ans=0;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout << ans;
	return 0;
}