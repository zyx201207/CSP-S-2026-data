#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int n,k,ans=0,aim=-1;
vector<int> mp[N+10];
void add(int x,int y) {
	mp[x].push_back(y);
} int dfs(int x,int fa) {
	int maxn=0;
	for(int y:mp[x]) {
		if(y==fa) continue;
		int ret=dfs(y,x);
		maxn=max(maxn,ret);
	} if(maxn==aim) {
		ans++; return 0;
	} return maxn+1;
} bool check(int aaa) {
	ans=0; aim=aaa-1;
	dfs(1,0);
	return ans<=k;
} void work() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) mp[i].clear();
	for(int i=1,x,y;i<n;i++) {
		cin>>x>>y;
		add(x,y),add(y,x);
	} if(n==k) return void(cout<<"0\n");
	int l=1,r=n,best=-1;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1,best=mid;
		else l=mid+1;
	} cout<<best<<'\n';
	return ; 
} signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int Test,t; cin>>Test>>t; cout<<t<<endl;
	while(t--) work(); 
	return 0;
}
