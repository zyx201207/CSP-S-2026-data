#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+7;
int n,m;
int a[N];
vector<int>vec;
int ans;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(m==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vec.push_back(a[i]);
	}
	for(int k=31;k>=0;k--){
		vector<int>tmp;
		for(auto v:vec)if((v>>k)&1)tmp.push_back(v);
		if(tmp.size()<m)continue;
		vec=tmp;
	}
	ans=vec[0];
	for(auto v:vec)ans&=v;
	cout<<ans<<'\n';
} 
