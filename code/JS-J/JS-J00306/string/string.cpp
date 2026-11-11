#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
int n,a[N];
long long len,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) {
	    int x;
        char y;
	    cin >> x >> y;
	    a[i]= a[i-1] + x;
	    c[i] = y;
	    len += x;
    }
    int now = 0,l = 1,r = n,ll = a[1],lr = len-a[n-1];
	while (now <= (len+1) / 2 && l <= r){
        if (c[l] != c[r]) ans += min(ll,lr);
        if (ll == lr){
            now += ll;
            l++;
            r--;
            ll = a[l] - a[l-1];
            lr = a[r] - a[r-1];
        }
        else if (ll > lr){
            now += lr;
            r--;
            ll -= lr;
            lr = a[r] - a[r-1];
        }
        else {
            now += ll;
            l++;
            lr -= ll;
            ll = a[l] - a[l-1];
        }
	}
	cout << ans;
    return 0;
}
