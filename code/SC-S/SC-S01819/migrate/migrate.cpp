#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		ll N,D;
		cin>>N>>D;
		ll x[N+5];
		for(int i=1;i<=N;i++){
			cin>>x[i];
		}
		ll s=x[2]-x[1];
		ll X=D/s;
		ll L=X+X-1;
		cout<<N-L+1<<'\n';
	}
	return 0;
}
