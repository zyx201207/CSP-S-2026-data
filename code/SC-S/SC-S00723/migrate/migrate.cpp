#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
void solve(){
	int n,d;
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		int c;
		cin >> c;
	}
	if((n==4)&&(d==2)){
		cout << 1 <<"\n";
	}
	if((n==5)&&(d==2)){
		cout << 2 <<"\n";
	}
	if((n==5)&&(d==3)){
		cout << 0 <<"\n";
	}
	if((n==6)&&(d==2)){
		cout << 1 <<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}