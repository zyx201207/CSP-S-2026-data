#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>vec,vec2;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;vec.push_back(x);
	}
	int ans=0;
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int v:vec){
			if(v & (1<<i))cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			vec2.clear();
			for(int v:vec)if(v&(1<<i))vec2.push_back(v);
			vec=vec2;
		}
	}
	cout<<ans<<'\n';
}
