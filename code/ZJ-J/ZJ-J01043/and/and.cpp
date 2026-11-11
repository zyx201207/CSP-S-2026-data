#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int>a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	for(int j=30;j>=0;j--){
		vector<int>tmp;
		tmp.clear();
		for(auto &x : a)if((x>>j)&1)tmp.push_back(x);
		if(tmp.size()>=m)ans+=(1<<j),swap(tmp,a);
	}
	cout<<ans;
	return 0;
}
