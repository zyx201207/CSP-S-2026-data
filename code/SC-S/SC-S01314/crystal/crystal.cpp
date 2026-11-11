#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	sort(a+1, a+1+n);
	int mx=-1e18;
	for(int f=1;f<=n;f++){
		int cnt=0, tot=0;
		int k=f;
		while(m>=tot&&k>0){
			cnt++;
			k--;
			tot+=(a[f]-a[k]);
		}
		mx=max(mx, cnt);
	}
	cout << mx << '\n';
	return 0;
}