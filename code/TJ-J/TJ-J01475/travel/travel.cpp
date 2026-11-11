#include<bits/stdc++.h>
using namespace std;
string a , b , c , d ;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> c >> b >> d ;
	if(a!=b)printf("0000");
	else if(c.substr(0,2)!=d.substr(0,2))printf("1000");
	else if(('A'<=c[2]&&c[2]<='C')&&('D'<=d[2]&&d[2]<='F')||
			('A'<=d[2]&&d[2]<='C')&&('D'<=c[2]&&c[2]<='F'))
		printf("1100");
	else if((c[2]=='C'&&d[2]=='D')||(c[2]=='C'&&d[2]=='D')||abs(d[2]-c[2])!=1)printf("1110");
	else printf("1111");
	return 0;
}