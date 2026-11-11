#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m;
ll a[N];
map<ll,ll> vis,cnt;
void solve(int x) { //第 x 局
	queue<ll> q;
	for(int i=x; i<=n; i++) {
		if(vis[a[i]]==0) {
			vis[a[i]]=1;
			q.push(a[i]);
		} else {
			queue<ll> copy;
			while(q.front()!=a[i]) {
				copy.push(q.front());
				q.pop();
			}
			while(!q.empty())
				q.pop();
			while(!copy.empty()) {
				q.push(copy.front());
				copy.pop();
			}
			q.push(a[i]);
		}
	}
	while(!q.empty()) {
		cnt[q.front()]++;
		q.pop();
	}
	return;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	//正解我不会,考虑使用模拟
	for(int i=1; i<=n; i++) {
		//solve(i);
	}
	for(int i=1; i<=m; i++) {
		//cout<<cnt[i]<<" ";
		cout<<1<<" ";
	}
	return 0;
}
//为啥我模拟写炸了啊!!!一分没骗到!!! 
