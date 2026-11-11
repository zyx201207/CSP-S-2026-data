#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c){
		cout << "1";
		if(b+1==d||d+1==b){
			cout << "1" << "1" << "1";
		}
		else{
			cout << "0" << "0" <<"0";
		}
	}
	else{
		cout << "0" << "0" <<"0"<<"0";
	}
	return 0;
}
