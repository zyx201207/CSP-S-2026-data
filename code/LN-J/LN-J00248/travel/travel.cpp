#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char s,p;
	cin >> a >> b >> s >> c >> d >> p;
	if(a==c){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	if(b==d){
		cout << "1";
	}else{
		cout << "000";
		return 0; 
	}
	if(s<='C'&&p<='C'){
	    cout << "1";
	    if(abs(s-p)==1){
			cout << "1";
		}else{
			cout << "0";
		}
	}else{
		if(s=='F'&&p=='D'){
			cout << "11";
			return 0;
		}
		if(s=='D'&&p=='F'){
			cout << "11";
			return 0;
		}else{
			cout << "00";
			return 0;
		}
	}
	return 0;
}
