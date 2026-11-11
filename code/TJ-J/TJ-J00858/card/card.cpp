#include<bits/stdc++.h>

using namespace std;

int n,m,ans[300009];
bool fa[300009];
queue<int> q1,q2;
stack<int> st1,st2;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int l;
		cin >> l;
		q1.push(l);
		q2.push(l);
	}
	for (int i = 1; i <= n; i++) {
		while(!q1.empty()) {
			int l = q1.front();
			q1.pop();
			if (fa[l]) {
				while(!st1.empty()) {
					int l1 = st1.top();
					if (l1 == l) {
						break;
					}
					st1.pop();
				}
			}else{
				st1.push(l);
				fa[l] = true;
			}
		}
		while(!st1.empty()){
			int l = st1.top();
			st1.pop();
			ans[l]++;
		}
		memset(fa,0,sizeof(fa));
//		cout << q2.size() << ' ';
		q2.pop();
		q1 = q2;
	}
	for (int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
