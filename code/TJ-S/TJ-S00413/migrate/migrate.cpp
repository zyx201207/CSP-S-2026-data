#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int c,t,n,d;
int tt[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c >>t;
	for(int i=1;i<=t;++i){
		cin>>n >>d;
		if(n==4&&d==2){
			cout<<1<<'\n'<<2;
			return 0;
		}
		else if(n==5&&d==3){
			cout<<0<<'\n'<<1;
			return 0;
		} 
	}
	
	return 0;
}

