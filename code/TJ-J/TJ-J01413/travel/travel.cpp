#include <bits/stdc++.h>
using namespace std;

string ta, tb, so, sq;
bool a=0, b=0;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ta >> so >> tb >> sq;
	int d = so[0] *10 + so[1] ;
	int e = sq[0] *10 + sq[1] ;
	if (ta != tb){
		cout << "0000";
		return 0;}
	else if(ta==tb){
		cout << "1";
		b=1;
	} 
	if ( ta==tb && d==e) {
		cout << "1";
		a=1;
	}
	else cout << "0";
	if(b==1 && a==1 &&( ( 'A' <= so[2] <='C'  && 'A' <= sq[2] <='C') || ( 'D' <= so[2] <='F' && 'D' <= sq[2] <='F'))) {
		cout << "1";  
	}
	else cout << '0';
	if(b==1 & a==1 && (so[2] == sq[2] + 1 || so[2] == sq[2] -1)){
		cout << "1";
	}
	else{
		
		if( b==1 && (d== e+1 || d==e-1) && so[2] == sq[2]) cout << "1";
		else cout << "0";
		
	}
	
	
	
	return 0;
}
