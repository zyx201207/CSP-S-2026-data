#include <bits/stdc++.h>
using namespace std;

long long c,t,i;
int main(){
	i=2;
	cin >> c >> t;
	while (t--){
		if (i%2==0)i--;
		else i++;
		cout << i << endl;
	}
	return 0;
}

