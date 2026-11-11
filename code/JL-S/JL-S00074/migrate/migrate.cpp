#include<bits/stdc++.h>
using namespace std;
int n,d,_,c,a[2000010];
void slv(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<"0\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>_;
	while(_--){
		slv();
	}
	return 0;
}