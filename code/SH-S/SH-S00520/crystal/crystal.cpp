#include<bits/stdc++.h>//14:38 pass
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
inline ll read(){
	ll x = 0,f = 1;
	char c = getchar();
	while(('0' > c || c > '9') && c != '-')c = getchar();
	if(c == '-')f = -1,c = getchar();
	while('0' <= c && c <= '9')x = x * 10 + c - 48,c = getchar();
	return x * f;
}
#define N 500005
ll n,k,a[N],ans,sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),k = read();
	rep(i,1,n)a[i] = read();
	sort(a + 1,a + n + 1);
	rep(i,1,n)sum[i] = sum[i - 1] + a[i];
	ans = 1;
	rep(i,2,n){
		ll l = 1,r = i,res;
		while(l <= r){
			ll mid = (l + r) >> 1;
			if(sum[i - 1] - sum[mid - 1] + k >= (i - mid) * a[i])res = mid,r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans,i - res + 1);
	}
	cout << ans << endl;
	return 0;
}
