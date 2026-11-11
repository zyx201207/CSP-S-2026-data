#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		cout << (ceil((n + 1) / 4.0) - k / 2)  / 2 + 1 << '\n';
	}
	return 0;
}