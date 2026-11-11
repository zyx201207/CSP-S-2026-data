#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 100;
template<typename TY>
void read(TY &s){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	s = x * f;
}
int n;
ll m;
ll a[N];
//bool check(int x){
//	for(int i=1;i+x-1<=n;i++){
//		ll cnt = 0;
//		for(int j=i;j<=i+x-1;j++){
//			cnt += (a[i+x-1] - a[j]);
//		}
//		if(cnt <= m) return true;
//	} 
//	return false;
//}
bool check1(int x){
	ll cnt = 0;
	for(int i=1;i<=x;i++){
		cnt += (a[x] - a[i]); 
	}
	if(cnt <= m) return true;
	int i = 1,j = x;
	while(j <= n){
		cnt -= (a[j] - a[i]);
		i++,j++;
		if(j > n) break;
		cnt += (a[j] - a[j - 1]) * x;
		if(cnt <= m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n); read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+n+1);
	int l = 0,r = n,ans = 0;
	while(l <= r){
		int mid = ((l + r)>>1); 	
		if(check1(mid)) l = mid + 1,ans = mid;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
