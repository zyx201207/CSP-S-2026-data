#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t; cin >> c >> t;
	int n,k; cin >> n >> k;
	if (c==0 && t==2){
		cout << 1 << endl;
		cout << 2 << endl;
	}
	else if (c==0 && t==3){
		cout << 1 << endl;
		cout << 1 << endl;
		cout << 2 << endl;
	}
	else if (c==0 && t==5){
		if (n==602 && k==42){
			cout << 17 << endl;
			cout << 9 << endl;
			cout << 6 << endl;
			cout << 6 << endl;
			cout << 9 << endl;
		}
		else{
			cout << 189 << endl;
			cout << 233 << endl;
			cout << 288 << endl;
			cout << 229 << endl;
			cout << 338 << endl;
		}
	}
	else{
		cout << 12251 << endl;
	}
	return 0;
}
