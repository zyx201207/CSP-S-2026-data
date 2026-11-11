#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			ans = max(ans,a[i]);
		}
		cout << ans;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
	}
	if(m > 2){
		sort(a+1,a+n+1);
		ans = a[n];
		m = m-1;
		for(int i = n-1;i >= 0;i--){
			if(m == 0) break;
			m--;
			ans = ans & a[i];
		}
		cout << ans;
	}
	return 0;
}
