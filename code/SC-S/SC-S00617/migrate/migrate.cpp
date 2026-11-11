#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
#define int long long
int n,a[N],d;
bool bfs(int l,int r){
	queue<int> q;vector<int> v;
	v.push_back(l);
	bool flag = false;int num = 0;
	while(!v.empty()){
		for(int i : v) {
			q.push(i);
			if(i == r){
				flag = true;num++;
			}
		}
		v.clear();
		if(flag){
			break;
		}
		while(!q.empty()){
			int i = q.front(),j = l+1;q.pop();
			while(a[j]-a[i] <= d){
				v.push_back(j++);
			}
		}
	}
	return num==2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;cin >> C >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 0;i < n;i++) cin >> a[i];
		int ans = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				ans += bfs(i,j);
			}
		}
		cout << ans << '\n';
	}
}