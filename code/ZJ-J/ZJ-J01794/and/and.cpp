#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N];
vector<int> f[30];
vector<int> t;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=29;j>=0;--j){
			if(a[i]>>j&1) f[j].push_back(a[i]);
		}
	}
	int ans=0;
	for(int j=29;j>=0;--j){
		if(f[j].size()>=m){
			if(ans==0){
				ans+=(1<<j);
			}else{
				int cnt=0;
				for(int i=0;i<f[j].size();++i){
					if((f[j][i]&ans)==ans){
						cnt++;
					}
				}
				if(cnt>=m){
					ans+=(1<<j);
				}
			}
		}
	}
	cout<<ans;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
