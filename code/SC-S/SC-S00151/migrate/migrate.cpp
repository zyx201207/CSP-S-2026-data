#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int kk = 1;kk <= t;kk++){
		int n,a[5005],d;
		cin >> n >> d;
		for (int i = 1;i <= min(n,5000ll);i++){
			cin >> a[i];
		}
//		cout << 1;
		if (c<=10){
			int mt=d;
			int ans=0;
			int ja[50005];
			for (int i = 1;i <= 1e8;i++){
				ja[i]=0;
				if (i<=mt) continue;
				if (i>=mt*2) break;
				ja[i]=1;
//				cout << "#";
			}
			for (int i = 1;i <= n-1;i++){
				for (int j = i+1;j <= n;j++){
					if (ja[a[j]-a[i]]!=0) ans+=ja[a[j]-a[i]];
				}
			}
			cout << ans << '\n';
		}
		else if (c==11||c==12){
			int cha=a[2]-a[1];
			int mt=d/cha;
			int ans=0;
			int ja[5005];
			for (int i = 1;i <= n-1;i++){
				ja[i]=0;
				if (i<=mt) continue;
				if (i>=mt*2) break;
				ja[i]=1;
//				cout << "#";
			}
			for (int i = 1;i <= n-1;i++){
				ans+=ja[i]*(n-i);
			}
			cout << ans << '\n';
		}else{
			cout << 0 << '\n'; 
		}
//		cout << cha << '\n';
	}
	return 0;
}
//1 2 3 4 5 6

//11 1
//10 14
//-31 -24 -17 -10 -3 4 11 18 25 32