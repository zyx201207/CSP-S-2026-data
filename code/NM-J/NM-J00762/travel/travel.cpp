#include"bits/stdc++.h"
using namespace std;

string s1 , s2 , s3 , s4;

int main(){
	
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);

    cin >> s1 >> s2 >> s3 >> s4;
	
	bool same = true;
    if(s1 == s3) cout << 1 ; 
    else {cout << 0 ; same = false;}
	
	bool flag = true;
    int n1 = (s2[0] - '0') * 10 + (s2[1] - '0');
	int n2 = (s4[0] - '0') * 10 + (s4[1] - '0');

    if(n1 == n2 && same) {cout << 1 ; flag = true;}
    else {cout << 0 ; flag = false;}

    char a , b;

    a = s2[2] , b = s4[2];
	
    if(a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C' && flag && same) cout << 1;
    else if(a >= 'D' && a <= 'F' && b >= 'D' && b <= 'F' && a != 'E' && b != 'E' && flag && same) cout << 1;
    else cout << 0;

    if(a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C' && !(a != 'A' && b != 'C') && flag && same) cout << 1;
    else if(a >= 'D' && a <= 'F' && b >= 'D' && b <= 'F' && a != 'E' && b != 'E' && flag && same) cout << 1 ;
    else cout << 0;

	return 0;
}

