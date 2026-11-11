#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,isl;
int arr[2000020];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i<=n;i++){
			cin >> isl;
		}
		if(d<=2){
			cout << (n-1)/d << endl;
		}else{
			if((n-1)%d==1){
				cout << 0 << endl;
			}else{
				cout << (n-1)/d << endl;
			}
		}
	}
	return 0;
}

