#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int C,T,n;
ll d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		ll t=x[2]-x[1];//ЬиадA
//		cout<<"n:"<<n<<' '<<d<<' '<<t<<' ';
		if(d<t*2||n-(d/t*2-1)<0) cout<<0<<'\n';
		else cout<<n-(d/t*2-1)<<'\n';
	}
	return 0;
}
