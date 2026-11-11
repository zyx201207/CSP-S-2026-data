#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		int x = 0;
		for(int i = 1;i<=2;i++){
			int michele;
			cin >> michele;
			if(x ==0) x = michele;
			else x = michele - x;
		}
		int neko = d/x;
		if(neko <= 1){
			cout << 0 << endl;
			continue;
		}else{
			cout << (n-2+1)*n - (2+n)*(n-2+1)/2 << endl;
			continue;
		}
	}
	
}
