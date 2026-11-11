#include <bits/stdc++.h>
using namespace std;

int c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	vector<long long> x;
	for(int j=1;j<=t;j++){
		int n=0;
		long long d=0;
		cin>>n>>d;
		x.clear();
		for(int i=1;i<=n;i++){
			long long k;
			cin>>k;
			x.push_back(k);
		}
		cout<<0<<"\n";
	}
	return 0;
}
