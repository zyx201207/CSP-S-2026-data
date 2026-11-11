#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>v;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int z;
		cin>>z;
		v.push_back(z);
	}
	for(int i=30;i>=0;i--){
		int md=1<<i;
		int cnt=0;
		for(auto x:v){
			if(x&md) cnt++;
		}
		if(cnt>=m){
			vector<int>nv;
			for(auto x:v){
				if(x&md) nv.push_back(x);
			}
			v=nv;
		}
	}
	int as=v[0];
	for(auto x:v){
		as&=x;
	}
	cout<<as;
	return 0;
}

