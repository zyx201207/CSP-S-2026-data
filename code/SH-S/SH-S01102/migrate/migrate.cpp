#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,d;
	cin>>n>>d;
	vector<int>x;
	vector<int>g[n+1];
	for(int i=1;i<=n;i++){
		int xxx;
		cin>>xxx;
		x.push_back(xxx);
	}
	sort(x.begin(),x.end());
	int dif=x[1]-x[0];
	if(d>2*dif && d<3*dif){
		cout<<n-3+1<<endl;
	}
}
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
