#include <bits/stdc++.h>
using namespace std;

int a[200005];
int main(){
	freopen("and1.in","r",stdin);
	freopen("and1.out","w",stdout);
	int n,m;
	cin >> n >> m;
	
	for(int i = 0;i < n;i++)cin >> a[i];
	sort(a,a+n,greater<int>());
	int ans = a[0];
	for(int i = 1;i < m;i++){
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
