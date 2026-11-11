#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,tpa=1;
long long x[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
			if(i>=3){
				if(x[i]-x[i-1]!=x[i-1]-x[i-2]){
					tpa=0;
				}
			}
		}
		if(tpa==1){
			if(x[3]-x[2]<=d&&n-2>=0){
				cout << n-2;
			}
			else{
				cout << 0;
			}
		}
	}
	return 0;
}
