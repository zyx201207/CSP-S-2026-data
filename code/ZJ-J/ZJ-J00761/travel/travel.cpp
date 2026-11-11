#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int a,b,aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c >> s >> cc >> ss;
    a = (c[0] - '0') * 10 + (c[1] - '0');
    b = (s[0] - '0') * 10 + (s[1] - '0');
    aa = (cc[0] - '0') * 10 + (cc[1] - '0');
    bb = (ss[0] - '0') * 10 + (ss[1] - '0');
    if(a == aa) cout << 1;
    else{
    	cout << "0000";
    	return 0;
	}
    if(b == bb) cout << 1;
    else{
    	cout << "000";
    	return 0;
	}
    if((s[2] < 'D' && ss[2] < 'D') || (s[2] >= 'D' && ss[2] >= 'D')) cout << 1;
    else{
    	cout << "00";
    	return 0;
	}
	if(abs(s[2] - ss[2]) == 1) cout << 1;
	else cout << 0;
	return 0;
}