#include<bits/stdc++.h>
using namespace std;

const int N = 2*1e6+10;
long long c,t,n,d;
long long x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int j = 0;j < t;j++){
		cin >> n >> d;
		for(int i = 0;i < n;i++){
			cin >> x[i];
		}
		long long xx = (x[1]-x[0]);
		long long xxx = d / (xx);
		if(xxx < 2 || n-2*xxx+1 <= 0) cout << 0 << endl;
		else cout << n-2*xxx+1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
