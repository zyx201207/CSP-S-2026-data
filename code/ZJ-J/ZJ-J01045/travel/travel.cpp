#include <iostream>
#include <string>
using namespace std;
int abs(int a){
	return (a>0?a:-a);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c){
		cout << 1;
		if(b.substr(0,2)==d.substr(0,2)){
			cout << 1;
			if((b[2]>='A' and b[2]<='C' and d[2]>='A' and d[2]<='C')){
				cout << 1;
				if(abs(b[2]-d[2])==1)cout << 1;
				else cout << 0;
			}else if(d[2]>='D' and d[2]<='E' and b[2]>='D' and b[2]<='E'){
				cout << 11;
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	
	return 0;
}
