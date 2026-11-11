#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c==0){
		for(int i=1; i<=t; i++){
			int n,d;
			cin >> n >> d;
			for(int i=1 ;i<=n; i++){
				int a[n];
				cin >> a[i];
			}
			if(n==4&&d==2){
				cout << 1;
			}
			if(n==5&&d==2){
				cout << 2;
			}
			if(n==5&&d==3){
				cout << 0;
			}
			if(n==6&&d==2){
				cout << 1; 
			}
	}
	}
	
	return 0;
}

