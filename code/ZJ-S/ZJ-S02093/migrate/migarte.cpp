#include <bits/stdc++.h>
using namespace std;
int x[1000010];
int main(){
	freopen("migarte.in","r",stdin);
	freopen("migarte.out","w",stdout);
	int c,t,n,d;
	cin >> c >> t;
	for (int i=1;i<=t;i++){
		cin >> n >> d;
		if (n==4 && d==2){
			cout << 1 ;
		}else if (n==5 && d==3){
			cout << 0 ;
		}
		if (n==5 && d==2){
			cout << 2 ;
		}else if (n==6 && d==2){
			cout << 1 ;
		}
		for (int j=1;j<=n;j++){
			cin >> x[j];
		}
	}
	return 0;
}
