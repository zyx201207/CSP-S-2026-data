#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5+10;
ll n,m;
ll a[N],maxn = 0,maxn1 = 0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
		maxn1 = max(maxn1,a[i]);
	}
	if(m == 1) cout << maxn1;
	else if(m == 2){
		for(int i = 1;i < n;i++){
			for(int j = i+1;j <= n;j++){
				maxn = max(maxn,a[i] & a[j]);
			}
		}
	}
	else{
		sort(a+1,a+n+1);
		int l = 1,r = l+m-1;
		while(r <= n){
			ll he = a[l];
			for(int i = l+1;i <= r;i++){
				he = he & a[i];
			}
			maxn = max(he,maxn);
			l++;
			r++;
		}
	}
	cout << maxn;
	return 0;
}

