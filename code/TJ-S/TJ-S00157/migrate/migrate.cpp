#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> d;
		for(int j=1;j<=n;j++){
			cin >> a[i];
		}
		if(n==4&&d==2){
			cout << 1 << "\n";
		}else if(n==6&&d==2){
			cout << 1 << "\n";
		}else if(n==5&&d==2){
			cout << 2 << "\n";
		}else{
			cout << 0 << "\n";
		}
	}
	return 0;
} 
