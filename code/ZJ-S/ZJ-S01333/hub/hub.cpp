#include<bits/stdc++.h>
using namespace std;
long long n,k,cont=0;
vector<long long>edge[1000010];
long long dfs(long long x,long long u,long long d,long long fa) {
	if(cont>k) {
		return 0;
	}
	long long r=0,c=0;
	for(auto it:edge[u]) {
		if(it!=fa) {
			long long tmp=dfs(x,it,d+1,u);
			r=max(r,tmp);
			if(tmp>=x) {
				c++;
			}
			if(cont>k) {
				return 0;
			}
		}
	}
	if((d>=x&&r>=x)||c>=2) {
		cont++;
//		cout<<"!!!"<<u<<endl;
	}
	return r+1;
}
bool check(long long x) {
//	cout<<"---\n";
	long long mmin=1e18;
	for(int i=1; i<=n; i++) {
		cont=0;
//		cout<<"-"<<i<<endl;
		for(auto it:edge[i]) {
			dfs(x,it,1,i);
		}
		mmin=min(mmin,cont);
	}
	if(mmin>k) {
		return 0;
	}
	return 1;
}
void solve() {
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		edge[i].clear();
	}
	for(int i=1; i<n; i++) {
		long long u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if(n==k){
		cout<<0<<endl;
		return;
	}
	long long l=1,r=n;
	while(l<r) {
		long long mid=l+r>>1;
		if(check(mid)) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	cout<<l<<endl;
}
int main() {
//	freopen("E:/down/hub/hub3.in","r",stdin);
//	freopen("E:/down/hub/hub.out","w",stdout);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		solve();
	}
	return 0;
}
/*6 5
1 2
2 5
4 5
5 3
3 6*/