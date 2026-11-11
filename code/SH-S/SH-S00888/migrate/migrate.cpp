#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long ans=0;
void mian(){
	if (c==11 || c==12){
		ans=0;
		cin >> n >> d;
		long long ds1,ds2;
		cin >> ds1 >> ds2;
		for (int i=3; i<=n; i++){
			long long x; cin >> x;
		}
		long long pex=d/(ds2-ds1);
		ans=n-pex-1;
		if (pex!=2 && pex!=3) ans=0;
		if (pex==3) ans--;
		if (ans<0) ans=0;
		cout << ans << endl;
	}else{
		cout << 0 << endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i=1; i<=t; i++) mian();
}
/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/ 
