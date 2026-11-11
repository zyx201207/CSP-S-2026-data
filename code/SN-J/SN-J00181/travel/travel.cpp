#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;cin >> a>>b>>c>>d;
	if(a==c) cout << '1';
	else{
		cout << "0000";
		return  0; 
	}
	
	int x=(b[0]-'0')*10+(b[1]-'0'),y=(d[0]-'0')*10+(d[1]-'0');
	if(x == y) cout << '1';
	else{
		cout << "000";
		return 0;
	}
	
	if(b[2] >='A' && b[2] <= 'C'){
		if(d[2] >= 'A' && d[2] <= 'C') cout << '1';
		else{
			cout << "00";
			return 0;
		}
	}else{
		if(d[2]>='D' && d[2]<='F') cout << '1';
		else{
			cout << "00";
			return 0;
		}
	}
	
	if(abs(b[2]-d[2]) == 1){
		if(b[2]=='C' && d[2]=='D') cout << '0';
		else if(b[2]=='D' && d[2]=='C') cout << '0';
		else cout << '1';
	}else cout << '0';
	return 0;
}
 
