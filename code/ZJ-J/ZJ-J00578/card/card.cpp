#include<bits/stdc++.h>
using namespace std;

long long a[500005],vis[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	//n场游戏
	for(long long i=1; i<=n; i++) {
		queue<long long> q;
		for(long long j=i; j<=n; j++) {
			//拿出牌
			queue<long long> now;
			while(!q.empty()) {
				now.push(q.front());
				q.pop();
			}
			while(!now.empty()) {
				if(now.front()==a[j]) break;
				q.push(now.front());
				now.pop();
			}
			//加牌
			q.push(a[j]);
		}
		while(!q.empty()) {
			vis[q.front()]++;
			q.pop();
		}
	}
	for(long long i=1; i<=m; i++) {
		cout<<vis[i]<<" ";
	}
	//记得改long long
	return 0;
}
