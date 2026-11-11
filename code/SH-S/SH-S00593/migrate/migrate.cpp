#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[3000000];
int l[3000000], r[3000000];
int dp[3000000], pd[3000000];
int sd[3000000], sp[3000000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); 
	int c,t;cin>>c>>t;
	mt19937 rnd(time(0));
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=0;i<=n;i++) dp[i] = pd[i] = l[i] = r[i] = sd[i] = sp[i] = 0;
		for(int i=1,j=1;i<=n;i++){
			while(a[i]-a[j] > d) j++;
			l[i] = j;
		}
		for(int i=n,j=n;i>=1;i--){
			while(a[j]-a[i] > d) j--;
			r[i] = j;
		}
		int ans = 0;
	//	for(int i=1;i<=n;i++) cout << l[i] <<' ';cout<<endl;
	//	for(int i=1;i<=n;i++) cout << r[i] << ' ';cout<<endl;
		for(int i=1;i<=n;i++){
			if(l[i]==i){
				dp[i] = 1; continue;
			}
			int pos = upper_bound(r+1,r+n+1,i) - r - 1;
			if(r[l[i]] == i) {
				dp[i] = dp[l[i]] + 1 + (max(l[i],pos)-l[i]);
			}
			else {
				int sop = max(l[i]+1, lower_bound(r+1,r+n+1,i) - r);
				dp[i] = 1 + max(0LL, max(l[i],pos)-sop+1);
			}
		//	cout <<i <<':' <<dp[i] << ' ' << max(l[i],pos) << endl;
		}
		for(int i=n;i>=1;i--){
			if(r[i]==i){
				pd[i] = 1; continue;
			}
			int ll = i+1, rr = r[i]-1, res = r[i];
			while(ll<=rr){
				int mid = (ll+rr)>>1;
				if(l[mid] >= i){
					rr = mid - 1, res = mid;
				}
				else ll = mid + 1;
			}
			if(l[r[i]] == i) {
				pd[i] = pd[r[i]] + 1 + (r[i]-res);
			}
			else {
				int ll = i+1, rr = r[i]-1, ser = r[i]-1;
				while(ll<=rr){
					int mid = (ll+rr)>>1;
					if(l[mid] <= i){
						ll = mid + 1; ser = mid;
					}
					else rr = mid - 1;
				}
				pd[i] = 1 + (ser-res+1);
			}
		//	cout << i <<':' <<pd[i] << ' ' <<res << endl;
		}
		for(int i=1;i<=n;i++) sd[i] = sd[i-1] + dp[i], sp[i] = sp[i-1] + pd[i];
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				vector<int> f, s;
//				for(int k=i;k<j;k=r[k]){
//					f.push_back(k);
//					if(k == r[k]) break;
//				} 
//				if(r[f.back()] == f.back()) continue;
//				f.push_back(j); 
//				for(int k=j;k>i;k=l[k]){
//					s.push_back(k);
//					if(k == l[k]) break;
//				}
//				if(l[s.back()] == s.back()) continue;
//				s.push_back(i);
//				int cnt = 0;
//				for(int k=0;k<f.size();k++) cnt += f[f.size()-1-k]-s[k];
//				if(cnt == 1){
//		//			cout << i << ' ' << j <<endl;
//					ans ++;
//				}
//			}
//		}
//		cout << ans << endl;
//		int res = 0;
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(r[i] == i || l[j] == j) continue;
//				int x = r[i]-1, y = l[j];	
//				if(x == i || y+1 == j) continue;
//			//	if(l[x] != i || r[y+1] != j) continue;
//				if(x == y){
//		//			cout << i << ' ' <<j << ' ' << x << ' ' << y << ' ' <<dp[i] << ' ' << pd[j] << ' ' <<l[x] <<' ' <<r[y+1]<<endl;
//					res += (l[x] == i ? dp[i] : 1) * (r[y+1] == j ? pd[j] : 1);
//	//				cout << res <<endl;
//				}
//			}
//		}
//		cout << res << endl;
		ans = 0;
		for(int i=1;i<=n;i++){
			if(r[i] == i) continue;
			if(l[r[i]-1] != i){
				if(r[r[i]] == r[i]) continue;
				int ll = lower_bound(l+1,l+n+1,r[i]-1) - l, rr = upper_bound(l+1,l+n+1,r[i]-1) - l - 1;
				ans += max(0LL, min(rr,r[r[i]]-1)-max(ll,r[i]+1)+1);
				int y = r[r[i]];
				if(l[y] == r[i]-1){
					ans += pd[y];
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(l[i] == i) continue;
			if(r[l[i]+1] != i){
				if(l[l[i]] == l[i]) continue;
				int y = l[l[i]];
				if(r[y] == l[i]+1){
					ans += dp[y];
				}
			}
			else{
				if(l[l[i]] == l[i]) continue;
				int y = l[l[i]];
				if(r[y] == l[i]+1){
					ans += pd[i] * dp[y];
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(r[i] == i || l[j] == j) continue;
//				int x = r[i]-1, y = l[j];	
//				if(x == i || y+1 == j) continue;
//				if(x == y && l[x] == i && r[y+1] == j){
//					ans += dp[i] * (r[y+1] == j ? pd[j] : 1);
//				}
//			}
//		}
		cout << ans << endl;
	}
}
