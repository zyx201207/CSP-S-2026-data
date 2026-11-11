#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
bool f[500005];
int ff[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		queue <int> q;
		for(int j = 1;j <= n;j++){
			if(f[j] == 0) {
				q.push(a[j]);
				f[j] = 1;
			}
			else{
				while(!q.empty()) q.pop();
				q.push(a[j]);
			}
		}
		int x = 0;
		while(!q.empty()){
			x = q.front();
			ff[x]++;
			q.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ff[i] << " "; 
	}
	return 0;
}
