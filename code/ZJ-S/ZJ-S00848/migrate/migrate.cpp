#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
    	int n,d;
    	cin >> n >> d;
    	for(int i = 1;i<=n;i++){
	    	cin >> a[i];    
		}
		sort(a+1,a+n+1);
		if(c==11||c==12){
			int c = a[2]-a[1];
			int x = d/c*2;
			if(x>n){
				cout << 0 << "\n";
			}else{
				cout << n-x+1 << "\n";
			}
			for(int i = 1;i<=n;i++){
			    a[i] = 0;
			}
			continue;
		}
		int dqc = a[2]-a[1];
		int l = 1,r = 2,cd = 2,c = a[2]-a[1];
		int dql = 1,dqr = 2,dqcd = 2;
		for(int i = 3;i<=n;i++){
	    	int x = a[i]-a[i-1];
	    	if(x==dqc){
	    		dqr++;
	    		dqcd++;
			}else{
				if(dqcd>cd){
					c = dqc;
					cd = dqcd;
					l = dql;
					r = dqr;
				}
				dqcd = 1;
				dql = i;
				dqr = i;
				dqc = x;
			}
		}
		if(dqcd>cd){
			c = dqc;
			cd = dqcd;
			l = dql;
			r = dqr;
		}
		n = cd;
		int x = d/c*2;
		if(x>n){
			cout << 0 << "\n";
		}else{
			cout << n-x+1 << "\n";
		}
//		cout << c << " " << cd << " " << l << " " << r << "\n";
		for(int i = 1;i<=n;i++){
		    a[i] = 0;
		}
	}
	return 0;
}
