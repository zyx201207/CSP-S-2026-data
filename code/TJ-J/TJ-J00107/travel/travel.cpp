#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	int a,b,e,d;
	int q=0,w=0,r=0,t=0;
	cin >> a  >> b;
	char c,f;
	cin >> c;
	cin >> d >> e;
	cin >> f;
	if(a==d)  q=1;
	if(q&&b==e) w=1;
	if(w&&(c=='A'||c=='B'||c=='C')&&(f=='A'||f=='B'||f=='C')) {
		r=1;
		if((c=='A'&&f=='B')||(c=='B' && f=='A')||(c=='B' && f=='C')||(c=='C' && f=='B')) t=1;
	}
	if(w&&(c=='D'||c=='F')&&(f=='D'||f=='F')){
		r=1;
		t=1;
	}
	cout << q << w << r << t;
	return 0;
}
