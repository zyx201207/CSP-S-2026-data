#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000009],cnt[2000009],s,e,u[2000009],ans,g[2000009];
struct node{
	int e,i;
}v[2000009];
bool operator < (node a,node b){
	return a.e > b.e;
}
priority_queue <node> q;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			cnt[i] = u[i] = 0;
		}
		ans = 0;
		for(int i = 1;i <= n;i++){
			int l = i,r = n;
			while(l < r){
				int mid = ((l + r + 1) >> 1);
				if(a[mid] - a[i] <= d){
					l = mid;
				}
				else{
					r = mid - 1;
				}
			}
			u[i] = l;
		}
		for(int j = 1;j <= n;j++){
			while(!q.empty())q.pop();
			for(int i = 0;i <= n;i++){
				g[i] = 0;
			}
			for(int i = j;i <= n;i++){
				while(!q.empty() && q.top().e < i){
					g[q.top().i]--;
					q.pop();
				}
				if(!q.empty())cnt[i] = q.top().i + 1;
				else cnt[i] = i - 1;
				q.push((node){u[i],cnt[i]});
//				cout << q.top().e << ' ' << q.top().i << '\n';
				g[cnt[i]]++;
				if(!q.empty() && g[q.top().i] == 2)ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
