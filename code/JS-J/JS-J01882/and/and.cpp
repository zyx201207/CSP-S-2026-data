#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,m,maxn = LLONG_MIN;
    cin>>n>>m;
    for (int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if (m == 1) {
		cout<<a[n];
		return 0;
	}
	else if (m == 2){
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				maxn = max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	else{
		maxn = a[n];
		for (int i = n-1;i >= n-m+1;i--){
			maxn = maxn & a[i];
		}
		cout<<maxn;
		return 0;
	}
    return 0;
}
