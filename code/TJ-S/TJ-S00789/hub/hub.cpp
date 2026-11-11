#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int y = t;
	while(t--){
		cout << y-t+1 << '\n';
	}
	return 0;
}
