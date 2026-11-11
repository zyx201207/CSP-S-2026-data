#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d;
	int a,c;
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << "1";
		if(b[0] - '0' == d[0] - '0' && b[1] - '0' == d[1] - '0'){
			cout << "1";
			cout << "10";
		}
		else{
			cout <<"000";
		}
	}
	else{
		cout << "0000";
	}
}
