#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[214514];
vector<int>v;
int ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	for(int i=30;i>=0;i--){
		
		vector<int>v2;
		for(int j=0;j<v.size();j++){
			if(v[j]>>i&1){
				v2.push_back(v[j]);
			}
		}
		if(v2.size()>=m){
			ans+=(1ll<<i);
			v=v2;
		}
	}
	cout<<ans;
	return 0;
}
