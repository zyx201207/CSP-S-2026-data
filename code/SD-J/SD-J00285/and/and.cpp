#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[210000];
int a[210000];
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		vis[i] = 0;
	}
	int ans = 0;
	vector<int> x;
	for(int i = 30 ; i >= 0 ; i--){
		x.clear();
		int num = 0;
		for(int j = 1 ; j <= n ; j++){
			if(vis[j]) continue;
			if(a[j]&(1<<i)) num++;
			else x.push_back(j);
		}
		if(num>=m){
			ans |= (1<<i);
			for(int j = 0 ; j < x.size() ; j++) vis[x[j]] = 1;
		}
	}
	cout << ans;
	return 0;
}
//rp++
