#include <bits/stdc++.h> 
using namespace std;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string as,bs;
	cin >> a >> as >> b >> bs;
	if(a==b){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	string as1=as.substr(0,2);
	string bs1=bs.substr(0,2);
	if(as1==bs1){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	if((as[2]>='A'&&as[2]<='C'&&bs[2]>='A'&&bs[2]<='C')||(as[2]>='D'&&as[2]<='F'&&bs[2]>='D'&&bs[2]<='F')){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if(max(as[2],bs[2])-min(as[2],bs[2])==1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
