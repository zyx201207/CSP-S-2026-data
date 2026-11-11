#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[500005];
int ct[500005];
int bj[300005];
int t[300005];
priority_queue <int> q;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		ct[i] = bj[a[i]];
		bj[a[i]] = i;
	}
	q.push(0);
	for(int i = 1;i <= m;i++) bj[i] = n + 1;
	for(int i = n;i >= 1;i--){
		while(q.top() >= i){
			q.pop();
		}
		int qid = q.top();
		if(bj[a[i]] > i){
			t[a[i]] += i - qid;
			bj[a[i]] = qid;
		}
		q.push(ct[i]);
	}
	for(int i = 1;i <= m;i++) cout << t[i] << " ";
	return 0;
}

