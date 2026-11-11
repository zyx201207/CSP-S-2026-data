#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 3e18;
struct fenwick{
	vector<int> data;
	int n;
	void init(int size){
		n = size;
		data.resize(n+1);
	}
	void add(int id, int x){
		id = id+1;
		while(id <= n){
			data[id] = max(data[id],x);
			id += id & (-id);
		}
	}
	int get(int id){
		id = id+1;
		if(id > n) return 0;
		int ans = 0;
		while(id){
			ans = max(ans,data[id]);
			id -= id & (-id);
		}
		return ans;
	}
};
void run(){
	int n, d;
	cin>>n>>d;
	vector<int> a(n);
	for(int i = 0; i <n; i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		vector<array<int,2>> dp(n,{inf,0});
		dp[i] = {0,1};
		for(int j = i; j < n; j ++){
			for(int k = j+1; k < n; k++){
				if(a[k] - a[j] > d) break;
				if(dp[k][0] > dp[j][0]+1) dp[k] = {dp[j][0]+1,0};
				if(dp[k][0] == dp[j][0]+1 ) dp[k][1] += dp[j][1];
			}
		}
		for(auto id: dp){
			if(id[1] == 2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	
}
void run2(){
	int n, d;
	cin>>n>>d;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	if(n == 1){
		cout<<0<<'\n';
	}
	else{
		int c = d/(a[1]-a[0]);
		if(c == 1 or c == 0){
			cout<<0<<'\n';
		}
		else{
			cout<<max(0ll,n-2*c+1)<<'\n';
		}
	}
}
void run3(){
//	cout<<'a'<<endl;
	fenwick f;
	int n, d;
	cin>>n>>d;
	f.init(n+1);
	vector<int> a(n);
	for(int i = 0; i <n; i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		vector<array<int,2>> dp(n,{inf,0});
		dp[i] = {0,1};
		for(int j = i; j < n; j ++){
			for(int k = max(j+1,f.get(dp[j][0])+1); k < n; k++){
				if(a[k] - a[j] > d) break;
				if(dp[k][0] > dp[j][0]+1) {
					dp[k] = {dp[j][0]+1,0};
					f.add(dp[k][0],k);
				}
				if(dp[k][0] == dp[j][0]+1 ) dp[k][1] += dp[j][1];
			}
		}
		for(auto id: dp){
			if(id[1] == 2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i = 0; i < t; i++){
		if(c <= 6)run();
		else if(c <= 10) run3();
		else if (c <= 12) run2();
	}
}