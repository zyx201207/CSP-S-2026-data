#include <bits/stdc++.h>
using namespace std;

int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i=1; i<=t; i++){

		int n,d;
		int xarr[19999];
		cin >> n >> d;
		for (int j=1; j<=n; j++){
			cin >> xarr[j];
		}

		int diff[19999],lig = 1;

		for (int j=3; j<=n+2; j++){
			diff[j-2] = xarr[j-1] - xarr[j-2];
			if (diff[j-2] > d && lig < 3){
				cout << 0;
				break;
			}else if(diff[j-2] > d){
				break;
			}else{
				break;
			}

		}




	}


	return 0;
}
