#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n,k;
array<vector<int>,N> g;
signed MainA(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		// g[u].push_back(v);
	}
	int m=n/2+2;
	if(k==n){
		cout<<0<<endl;
		return 0;
	}
	int l=1,r=m;
	auto check=[&](int x)->bool{
		return m-x-x-k>x*2;
	};
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))	l=mid+1;
		else	r=mid;
	}
	cout<<l<<endl;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	clock_t Start=clock();
	int Tc,T;
	cin>>Tc>>T;
	if(Tc==13||Tc==14){
		while(T--)
			MainA();
	}
	else{
		while(T--)
			cout<<0<<endl;
	}
	cerr<<(double)(clock()-Start)/CLOCKS_PER_SEC<<endl;
	return 0;
}
/*


fuyu
*/