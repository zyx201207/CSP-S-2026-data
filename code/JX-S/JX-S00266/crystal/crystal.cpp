#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1010101],as=-1e18;
unordered_map<int,int> ma;
void dfs(int ct){
	if(ct==0){
		ma.clear();
		int s=0;
		for(int i=1;i<=n;i++) ma[a[i]]++;
		for(auto p:ma) s=max(s,p.second);
		as=max(as,s);
	}
	for(int i=1;i<=n;i++){
		if(ct-1>=0){
			a[i]++;
			dfs(ct-1);
			a[i]--;
		}
		else break;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(m);
	cout<<as;
	return 0;
}
