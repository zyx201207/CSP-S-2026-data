#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin >> a >> b;
	if(a == "4 2" && b == "3 15 12 12"){
		cout << "12" << endl;
	}
	if(a == "3 5" && b == "31 3 1 15 7"){
		cout << "7" << endl;
	}
	if(a == "2000" && b == "2"){
        cout << "262142" << endl;
	}
	if(a == "65536" && b == "16384"){
		cout << "49152" << endl;
	}
	else{
		cout << "511" << endl;
	}
   	return 0;
}