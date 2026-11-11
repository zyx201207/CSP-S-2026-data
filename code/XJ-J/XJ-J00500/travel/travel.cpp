#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,c,d;
    bool aa=false,bb=false,cc=false,dd=false;
    cin >>a>>b>>c>>d;
    
    if (a==c){cout << 1;aa=true;}else{cout << 0;}
    if ((b[0]==d[0]&&b[1]==d[1])&&aa){cout << 1;bb=true;}else{cout << 0;}
    if (((b[2]>='A'&& b[2]<='C' && d[2]>='A' && d[2]<='C')&&aa&&bb)||(b[2]>='D'&& b[2]<='F' && d[2]>='D' && d[2]<='F')){cout << 1;cc=true;}else{cout << 0;}
    if ((((b[2]-d[2]==1)||(b[2]-d[2]==-1))&&(!((b[2]=='D'&&d[2]=='C')||(b[2]=='C'&&d[2]=='D'))))&&aa&&bb&&cc){cout << 1;}else{cout << 0;}
	
	return 0;
}