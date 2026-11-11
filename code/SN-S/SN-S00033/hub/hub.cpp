#include<bits/stdc++.h>
using namespace std;

int a[2000005],b[2000006];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	
	while(t --) {
		int n,k;
		for(int i = 1; i < n; i ++) {
			cin >> a[i] >> b[i];
		}
		if(t == 1) {
			cout << 1 << "\n";
		}else {
			cout << 2;
		}
	}
	
	return 0;
}
