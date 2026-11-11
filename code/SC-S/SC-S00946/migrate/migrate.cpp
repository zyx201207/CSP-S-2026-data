#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long cnt = 0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cnt = 0;
		long long n,d;
		cin >> n >> d;
		long long o = 1;
		while(n--){
			long long a;
			cin >> a;
			if(a % d == 0 && o >= 4)cnt++;
			o++;
		}
		cout << cnt << endl;	
	}
	return 0;
}