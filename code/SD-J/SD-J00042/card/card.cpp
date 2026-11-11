#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans[300005];
void solve_SUPER(){
	for(int i = 1;i <= n;i++)
		ans[a[i]] = i;
	for(int i = 1;i <= m;i++)
		cout << ans[i] << (i == m ? '\n' : ' ');
}
void solve_ULTRA(){
	stack<int> q;
	int l = 1,r = 1;
	for(int i = 1;i <= n;i++){
		q = stack<int>();
		int f[300005] = {};
		for(int j = i;j <= n;j++){
			if(f[a[j]]){
				while(!q.empty()){
					int u = q.top();
					q.pop();
					f[u]--;
					if(u == a[j]) break;
				}
			}
			q.push(a[j]);
			f[a[j]]++;
		}
		while(q.size()){
			int u = q.top();q.pop();
			ans[u]++;
		}
	}
	for(int i = 1;i <= m;i++)
		cout << ans[i] << (i == m ? '\n' : ' ');
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	bool f = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] < a[i - 1]) f = 0; 
	}
	if(f) solve_SUPER();
	else solve_ULTRA();
	return 0;
}
