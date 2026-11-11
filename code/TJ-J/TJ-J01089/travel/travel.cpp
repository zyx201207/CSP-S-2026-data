#include <bits/stdc++.h>
using namespace std;




int side(char x){ return x <= 'C' ? 0 : 1; } 
int pos(char x){ 
    if (x=='A') return 0;
    if (x=='B') return 1;
    if (x=='C') return 2;
    if (x=='D') return 0;
    return 1; 
}

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("taavel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool q1 = (c1==c2);
    string r1 = s1.substr(0,2), r2 = s2.substr(0,2);
    bool q2 = q1 && (r1==r2);
    char x = s1[2], y = s2[2];
    bool q3 = q2 && (side(x)==side(y));
    bool q4 = q3 && (abs(pos(x)-pos(y))==1);
    cout << q1 << q2 << q3 << q4 << "\n";
    return 0;
}
