#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000009
int n,d,x[N],l[N],r[N],f[N],g[N];
vector<int> p[N],q[N];
int calc(vector<int> &c,int x){ // >=x first pos
	int l = 0,r = c.size() - 1,ans = c.size();
	while(l <= r){
		int mid = (l + r) >> 1;
		if(c[mid] >= x) r = mid - 1,ans = mid;
		else l = mid + 1; 
	}
	// for(int i = 0;i < c.size();i++) cout<<c[i]<<" "; cout<<" qry "<<x<<" "<<ans<<endl; 
	return ans;
}
signed main(){
	// system("fc migrate.out migrate3.ans"); return 0;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i = 1;i <= n;i++) cin>>x[i],p[i].clear(),q[i].clear();
		int pos = 1;
		for(int i = 1;i <= n;i++){
			while(pos < i && x[pos] < x[i] - d) pos++;
			l[i] = pos; p[pos].push_back(i);
		}
		pos = n;
		for(int i = n;i >= 1;i--){
			while(pos > i && x[pos] > x[i] + d) pos--;
			r[i] = pos; q[pos].push_back(i);
		}
		for(int i = 1;i <= n;i++) sort(q[i].begin(),q[i].end());
		for(int i = 1;i <= n;i++){
			if(r[l[i]] == i) f[i] = f[l[i]] + 1;
			else f[i] = 1;
			f[i] += (l[i] + 1 <= i - 1 ? calc(q[i],i) - calc(q[i],l[i] + 1) : 0);
		}
		for(int i = n;i >= 1;i--){
			if(l[r[i]] == i) g[i] = g[r[i]] + 1;
			else g[i] = 1;
			g[i] += (i + 1 <= r[i] - 1 ? calc(p[i],r[i]) - calc(p[i],i) : 0);
		}
		// cout<<"L R F G"<<endl;
		// for(int i = 1;i <= n;i++) cout<<l[i]<<" "<<r[i]<<" "<<f[i]<<" "<<g[i]<<endl;
		int ans = 0;
		for(int i = 2;i < n - 1;i++){
			int a = (l[i] + 1 <= i - 1 ? calc(q[i + 1],i) - calc(q[i + 1],l[i] + 1) : 0);
			int b = (i + 2 <= r[i + 1] - 1 ? calc(p[i],r[i + 1]) - calc(p[i],i + 2) : 0);
			int c = (r[l[i]] == i + 1 ? f[l[i]] : 0);
			int d = (l[r[i + 1]] == i ? g[r[i + 1]] : 0);
			// cout<<"? "<<i<<" ["<<l[i] + 1<<" "<<i - 1<<"] "<<a<<"   ["<<i + 2<<" "<<r[i + 1] - 1<<"] "<<b<<endl;
			// cout<<c<<" "<<d<<endl;
			ans += (a + c) * (b + d);
		}
		cout<<ans<<endl;
	}
}
