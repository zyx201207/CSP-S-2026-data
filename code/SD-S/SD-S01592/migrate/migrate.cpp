#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+3;
int c114,_=1;
int n,d,minn,ans;
int a[N];
map<int,int> m;
void dfs(int l,int s,int e){
	if(l==e){
		minn=min(minn,s);
		m[s]++;
		return ;
	}else if(l>e) return ;
	for(int i=l+1;i<=e;i++){
		if(a[i]-a[l]<=d) dfs(i,s+1,e);
		else break;
	}
	return ;
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			m.clear();
			minn=2e18+3;
			dfs(i,0,j);
			if(m[minn]==2){
				ans++;
				//cout<<i<<" "<<j<<'\n';
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c114>>_;
	while(_--) solve();
	return 0;
}

