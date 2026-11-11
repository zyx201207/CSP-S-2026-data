#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int c,t,n,d,x[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		int pos=0,ans=0;
		cin >> n >> d;
		for (int i=1;i<=n;i++) cin >> x[i];
		for (int i=1;i<=n;i++)
			if (x[i]-x[1] <= d and x[n]-x[i] <= d) pos=i;
		ans = (pos-1)*(n-pos);
		cout << pos << endl;
	}
	return 0;
} 
