#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,a[N];
bool fl[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i = 1;i <= n;++ i){
		cin>>a[i];
	}
	int ans = 0;
	for (int j = 30;j >= 0;-- j){
		int cnt = 0;
		for (int i = 1;i <= n;++ i){
			if (fl[i]) continue;
			if (a[i] & (1 << j)) cnt ++;
		}
		if (cnt < m) continue;
		ans += 1 << j;
		for (int i = 1;i <= n;++ i){
			if (fl[i]) continue;
			if (a[i] & (1 << j)) continue;
			fl[i] = 1;
		}
	}
	cout<<ans;
	return 0;
}