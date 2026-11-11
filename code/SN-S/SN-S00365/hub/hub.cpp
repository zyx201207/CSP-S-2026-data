/*
西安辅轮中学
韩谦益 
SN-S00365
*/
#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> e[1000010];
bool check(int mid) {
	int sum = 0;
	int cnt = 0;
	queue<int> quex;
	queue<int> quefa;
	queue<int> quesum;
	quex.push(1);
	quefa.push(0);
	quesum.push(0);
	while(!quex.empty()) {
		int u = quex.front(),fa = quefa.front();
		int ssum = quesum.front();
		quex.pop();
		quefa.pop();
		quesum.pop();
		if(cnt != 2 && ssum == mid+1) {
			sum++;
			cnt++;
			ssum = 0;
		}
		if(cnt == 2) {
			if(sum < k) {
				sum++;
				ssum = 0;
			}
		}
		if(ssum == mid+1) {
			return false;
		}
		for(int i = 0;i<e[u].size();i++) {
			int v = e[u][i];
			if(v != fa) {
				quex.push(v);
				quefa.push(u);
				quesum.push(ssum+1);
			}
		}
	}
	return true;
}
void work() {
	cin>>n>>k;
	for(int i = 1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout<<1;
	int l = 1,r = n,ans = 0;
	while(l <= r) {
		int mid = (l+r)/2;
		if(!check(mid)) {
			l = mid+1;
		} else {
			r = mid-1;
			ans = mid;
		}
	}
	cout<<ans<<"\n";
	for(int i = 1;i<=n;i++) {
		e[i].clear();
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		work();
	}
	return 0;
}
