#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int>a,b;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a.push_back(x);
	}
	for(int i=29;i>=0;i--){
		for(auto x:a){
			if((x>>i)&1){
				b.push_back(x);
				// cout<<x<<" ";
			}
		}
		if(b.size()<m){
			b.clear();
			continue;
		}
		// cout<<i<<"\n";
		a=b,b.clear(),ans+=(1<<i);
	}
	cout<<ans;
}