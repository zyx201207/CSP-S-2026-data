#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
const int N=2e6+10;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(it i=1;i<=n;++i){
			cin>>x[i];
		}
		if(n>=3 && (x[3]-x[1])<=d){
			cout<<n-3<<'\n';
		}else {
			cout<<0<<'\n';
		}
	}
	return 0;
}

