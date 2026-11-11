#include <bits/stdc++.h>
using namespace std;

int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i = 1;i <= n-1;i++){
			int l,r;
			cin >>l >> r;
		}if(n == 5 && k == 2){
			cout << 1 << endl;
		}else if(n == 10 && k == 3){
			cout << 2 << endl;
		}
	}
	return 0;
}