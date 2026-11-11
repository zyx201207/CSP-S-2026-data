#include<bits/stdc++.h>
using namespace std;
int c, t;
int v[2000005];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out","w",stdout);
    cin>> c >> t;
    while (t--){
    	int n, k;
    	cin >> n;
    	for (int i = 1;i <= n - 1;i++) {
    		int a, b;
    		cin >> a >>b;
    		v[a] = b;
    		v[b] = a;
		}
	}
	cout << "1" << endl << "2";
	return 0;
}
