#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,a;
char c,s[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >> n;
	ll k = 1;
	for(int i = 1;i <= n;++i){
        cin >> a >> c;
        l += a;
        for(int j = 1;j <= a;++j) s[k++] = c;
	}
	ll ans = 0;
	for(int i = 1;i <= l / 2;++i) if(s[i] != s[l - i + 1]) ans++;
	cout << ans;
	return 0;
}
