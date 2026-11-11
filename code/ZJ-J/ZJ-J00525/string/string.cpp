#include<bits/stdc++.h>
using namespace std;
long long n;
struct Edge{
	long long num = 0;
	char ch;
}a[200005];
long long ll,rr,ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> a[i].num >> a[i].ch;
	}
	ll = 1,rr = n;
	while(ll < rr){
		if(a[ll].num < a[rr].num){
			if(a[rr].ch != a[ll].ch)ans += a[ll].num;
			a[rr].num -= a[ll].num;
			ll++;
		}else{
			if(a[ll].ch != a[rr].ch)ans += a[rr].num;
			a[ll].num -= a[rr].num;
			rr--;
		}
	}
	cout << ans;
	return 0;
}
