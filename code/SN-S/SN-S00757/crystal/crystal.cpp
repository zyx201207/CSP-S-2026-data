#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500000 + 7;
int a[N];
int debug[N];
int need[N];
int michele(int l,int r){ //¹Ø×¢¿¨ÇðÐ»Ð»ß÷ strinova ¶þ´ÎÔª´òÇ¹ß÷ 
	return (need[r] - need[l]);
}
int magic_michele(int l,int r){
	return (michele(l,r)) - (a[r]-a[l])*(l-1);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		need[i] = (a[i]-a[i-1])*(i-1);
		need[i] = need[i-1] + need[i];
	}
	int l=1,r=1;
	int ans = -1;
	while(l<=r && r <= n){
		int cost = magic_michele(l,r);
		if(cost <= m){
			ans = max(ans,r-l+1);
		}else{
			l++;
			r--;
		}
		r++;
	}
	cout << ans;
	return 0;
}
