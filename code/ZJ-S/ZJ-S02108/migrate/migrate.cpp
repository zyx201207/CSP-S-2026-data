#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for (int i=1;i<=t;i++){
		int n,d;
		cin >> n >> d;
		int x[n+10];
		for (int j=1;j<=n;j++){
			cin >> x[j];
		}
		cout << (n+n%2)/2-1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
