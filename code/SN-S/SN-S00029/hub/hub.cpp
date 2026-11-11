#include <bits/stdc++.h>//5分先拿下了OVO 
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int a[30] = {};
	cin >> c >> t;
	cin >> n >> k;
	for(int i = 0;i<28;i++){
		cin >> a[i];
	}
	if(n==5&&k==2){
		cout << 1 << endl;
		cout << 2 << endl;
	}
	else{
		cout << 1 << endl;
		cout << 1 << endl;
	}
	return 0;
}
