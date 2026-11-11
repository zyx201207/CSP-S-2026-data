#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int c, t;
int n;
ll d;
ll x[N];
int maxn[N],cnt[N];
ll minn[N];
struct node{
	int u;
	ll num;
};
void solve(int st){
	queue<node> q;
	node e;
	e.u = st;
	e.num = 0;
	q.push(e);
	while(!q.empty()){
		node r = q.front();
		q.pop();
		for(int i = r.u + 1; i <= maxn[r.u]; i++){
			if(r.num + 1 < minn[i]){
				minn[i] = r.num + 1;
				cnt[i] = cnt[r.u];
				node w;
				w.u = i;
				w.num = minn[i];
				q.push(w);
			} else if(r.num + 1 == minn[i]){
				cnt[i] += cnt[r.u];
				node w;
				w.u = i;
				w.num = minn[i];
				q.push(w);
			}
		}
	}
	return;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++){
			scanf("%lld", &x[i]);
			maxn[i] = i;
			for(int j = i - 1; j >= 1; j--){
				if(x[j] + d >= x[i]){
					maxn[j] = i;
				}else{
					break;
				}
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				minn[j] = n + 1;
				cnt[j] = 0;
			}
			cnt[i] = 1;
			solve(i);
			for(int k = i + 1; k <= n; k++){
				if(cnt[k] == 2){
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
