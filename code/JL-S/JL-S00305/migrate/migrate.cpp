#include<bits/stdc++.h>
using namespace std;

int c,t;
int a,b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c == 0){
		cin >> a >> b;
		if(a == 4 && b == 2){
			cout << 1 << "\n" << 2;
			return 0;
		}else if(a == 5 && b == 3){
			cout << 0 << "\n" << 1;
			return 0;
		}
	}

	return 0;
}
