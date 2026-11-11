#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin >> t;
	int a[t],d[t];
	int x[n*t];
	for(int i=0;i<t;i++){
		cin >> a[i] >> d[i];
		for(int j=1;j<=n;j++){
			cin >> x[i];
		}
	}
	
	return 0;
} 
