#include <bits/stdc++.h>
using namespace std;

long long c, t,n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		if(n == k) cout << "0\n";
		else cout << "1\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
