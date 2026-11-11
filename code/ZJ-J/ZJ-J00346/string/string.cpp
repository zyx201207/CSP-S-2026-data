#include<bits/stdc++.h>
using namespace std;

int n,a[200005] = {};
char c[200005] = {};
long long ans = 0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int l = 1,r = n;
	while(l < r){
		int y = min(a[l],a[r]);
		if(c[l] != c[r]){
			ans += y;
		}
		a[l] -= y;
		a[r] -= y;
		if(a[l] == 0) l++;
		if(a[r] == 0) r--;
	}
	cout << ans;
    return 0;
}
