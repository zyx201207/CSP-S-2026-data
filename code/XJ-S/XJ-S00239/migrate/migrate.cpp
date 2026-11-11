#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long int c,t;
	cin >> c >> t;
	long long int n[50000],d[50000],x[50000];
	for(long long int i=1;i<=t;i++){
		cin >> n[i] >> d[i];
		for(long long int j=1;j<=n[i];j++){
			cin >> x[j];
		}
	}
	for(long long int i=1;i<=t;i++){
		if(d[i]>=3){
			cout << 0 << "\n";
		}
		else{
			cout << 1 << "\n";
		}
	}
	return 0;
}
