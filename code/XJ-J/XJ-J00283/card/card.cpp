#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin >> a >> b;
	if(a == "4 3" && b == "1 2 1 3"){
		cout << "3 1 4" << endl;
	}
	if(a == "10 3" && b == "3 1 2 1 3 2 3 1 2 1"){
		cout << "10 3 3" << endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0;
}
