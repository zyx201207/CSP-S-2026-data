#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int x[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, d, ans=0;
		cin >> n >> d;
		vector<int> vec;
		for(int i=1;i<=n;i++){
			x[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		sort(x+1, x+1+n);
		for(int s=1;s<=n;s++){
			for(int e=s+3;e<=n;e++){
				int cnt=0;
				if(x[e]-x[s]<=d){
					continue;
				}
				for(int mid=s+1;mid<=e-1;mid++){
					if(x[mid]-x[s]<=d&&x[e]-x[mid]<=d){
						cnt++;
					}
				}
				if(cnt==2){
					ans++;
					vec.push_back(e);
				}
				int tot=0;
				for(auto ii : vec){
					if(x[ii]-x[s]<=d&&x[e]-x[ii]<=d){
						tot++;
					}
				}
				if(tot==2){
					ans++;
					vec.push_back(e);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}