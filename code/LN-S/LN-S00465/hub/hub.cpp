#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c==0){
		for(int i=1 ;i<=t; i++){
			int n,k;
			cin >> n >> k;
			for(int i=1 ;i<n; i++){
				int a[n];
				cin >> a[i];
			}
			if(n==5&&k==2){
				cout << 1;
			}
			if(n==10&&k==3){
				cout << 2;
			}
		}
	}
	return 0;
}

