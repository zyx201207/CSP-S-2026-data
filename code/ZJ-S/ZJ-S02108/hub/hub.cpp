#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin >> c >> t;
	for (int i=1;i<=n;i++){
		cin >> n >> k;
		int u[n+10],v[i+10];
		for (int i=1;i<n;i++) cin >> u[i] >> v[i];
		cout << k-1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
