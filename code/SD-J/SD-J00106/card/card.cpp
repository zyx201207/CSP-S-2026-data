#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),b(m+1,0);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int k=1;k<=n;k++) {
		queue<int> q;
		for(int i=k;i<=n;i++) {
			if(i==0) {
				continue;
			}
			if(!q.empty()&&q.front()==a[i]) {
				while(!q.empty()) {
					q.pop();
				}
			}
			q.push(a[i]);
		}
		vector<bool> vis(m+1,false);
		while(!q.empty()) {
			int u=q.front();
			if(!vis[u]) {
				b[u]++;
			}
			vis[u]=true;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<b[i]<<' ';
	}
	return 0;
}
