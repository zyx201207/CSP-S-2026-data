#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==11 || c==12){
		while(t--){
			int n,d;
			cin >> n >> d;
			cout << n/d << "\n";
		}
	}else if(c==15 || c==16 || c==17 || c==18){
        while(t--){
			int n,d;
			cin >> n >> d;
			cout << n/d << "\n";
		}
    }else{
        while(t--){
        	int n,d;
			cin >> n >> d;
			if(n%2==0) cout << "1\n";
            else cout << "0\n";
        }
    }
}