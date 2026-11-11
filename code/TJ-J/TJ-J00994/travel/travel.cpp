#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    string a,b;
	int c,d;
    a=s1[0]+s1[1];
    b=s2[0]+s2[1];
    c=s1[2];
    d=s2[2];
    if (c1!=c2){
        cout << "0000";
        return 0;
    }
    else if(a!=b){
        cout << 1000;
        return 0;
    }
    else if(c<='C' && d>='D' || c>='D' && d<='C'){
    	cout << 1100;
    	return 0;
	}
    else if(abs(c-d)!=1 || c=='C' || d=='C'){
        cout << 1110;
        return 0;
    }
    else{
        cout << 1111;
        return 0;
    }
}

