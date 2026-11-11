#include<bits/stdc++.h>
using namespace std;
int c,n,t,x,cc;
long long d[2500000],s[2500000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> x;
		for (int i=1;i<=n;i++) s[i]=0;
		for (int i=1;i<=n;i++) cin >>d[i];
		if (x<=d[2]-d[1]||x>=d[n]-d[1]) cout << 0 << "\n";
		else{
			if (d[n]-d[1]-x-x+1<0) cout << 0<< "\n";
			else {
				cc=lower_bound(d+1,d+n+1,2*x-1)-d;
				cout << d-cc+1 << "\n";
			}
		}
	}
	return 0;
}
