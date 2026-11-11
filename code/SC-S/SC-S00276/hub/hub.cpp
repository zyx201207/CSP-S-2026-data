#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int> G[N];
int c, T, n, k, ans;
//bool check(int d){
//
//}
//void solve(){
//	cin>>n>>k;
//	for(int i=1;i<n;i++){
//		int x,y;
//		cin>>x>>y;
//		G[x].push_back(x),G[y].push_back(y);
//	}
//	int l=0,r=n;
//	while(l<=r){
//		int mid=(l+r)>>1;
//		if(check(mid)){
//			r=mid-1;
//			ans=mid;
//		}
//		else l=mid+1;
//	}
//	cout<<ans<<"\n";
//}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
		}
		int m = n / 2;
		int p = (m - k + 4) / 3;
		cout << p << "\n";

	}
	return 0;
}