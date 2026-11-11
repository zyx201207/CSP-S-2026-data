#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e6 + 10;
int a[N];
int d[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >>n >> d;
		int D = 0;
		for(int i=1;i<=n;++i){
			cin >> a[i];
			if(i == 2){
				D = a[i]-a[i-1];  
			}
		}
		bool flag = 1;
		for(int i=1;i<=n;++i){
			if(a[i]-a[i-1]!=D){
				flag = 0;
			}
		}
		if(flag){
			if(d == D){
				cout << 0 <<"\n";
			}else if(D > d){
				int k = D/d;
				if(k == 1){
					cout << 0 <<"\n";
				}else if(k == 2){
					cout << 2 <<"\n";
				}else{
					cout << 1<<"\n";
				}
			}else{
				cout << 0 <<"\n";
			}
		}
		if(d&1){
			cout << 1<<"\n";
		}else{
			cout << 2<<"\n";
		}
	}
	
	return 0;
}
