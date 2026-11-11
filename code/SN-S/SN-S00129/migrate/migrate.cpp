#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;

long long c,t,n,d,x[N],ans;
int l[N],tail,head,r[N];
int pre[N],cnt,vis[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		tail = 1;
		head = n;
		for(int i=1;i<=n;i++){
			while(x[tail+1]-x[i]<=d&&tail<n)tail++;
			r[i] = tail;
			if(tail-i==1){
				pre[i] = pre[i-1] + 1;
			}
			else pre[i] = pre[i-1];
		}
		for(int i=n;i>=1;i--){
			while(x[i]-x[head-1]<=d&&head>1){
				head--;
			}
			l[i] = head;
			if(i-head==1)vis[i] = 1;
			else vis[i] = 0;
		}
		for(int i=4;i<=n;i++){
			if(vis[i]==1)ans += pre[i-3];
			if(pre[i]==pre[i-3])ans ++;
		}
		cout << ans << "\n";
	}
	return 0;
}
