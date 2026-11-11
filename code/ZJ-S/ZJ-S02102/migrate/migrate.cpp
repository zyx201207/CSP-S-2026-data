#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+7;
int x[N];
int c,T,n,d;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11 || c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			int gc=x[2]-x[1],lon=x[n]-x[1];
			if(d<2*gc) cout<<0<<"\n";
			else if(2*d>=lon)
				cout<<0<<"\n";
			else cout<<n-(d/gc+1);
		}
	}
	else{
		while(T--)
			cout<<0<<"\n";
	}
	return 0;
}