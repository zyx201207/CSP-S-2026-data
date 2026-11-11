#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[210000];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>v;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(auto it:v){
			if(it>>i&1)cnt++;
		}
		if(cnt>=m){
			vector<int>vv=v;
			v.clear();
			for(auto it:vv){
				if(it>>i&1){
					v.push_back(it);
				}
			}
			ans+=(1LL<<i);
		}
	}
	cout<<ans<<endl;
	return 0;
} 
