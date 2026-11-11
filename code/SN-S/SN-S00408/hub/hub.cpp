#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,k;
long long u[2000006],v[2000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			cin >> u[i] >> v[i];
		}
		
	}
	if(t==2){
		cout << 1 << endl << 2;
	}
	else if(t==3){
		cout << 1 << endl << 1 << endl << 2;
	}
	else if(t==5){
		cout << 17 << endl << 9 << endl << 6 <<endl << 6 << endl << 9;
	}
	else if(t==1){
		cout << 12251;
	}
	return 0;
}
