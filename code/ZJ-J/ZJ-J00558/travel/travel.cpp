#include<bits/stdc++.h>
using namespace std;
char a, b, c, d, e, f, g, h, i, j;
int main()
{
	freopen("travel.in ","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	if(a==f&&b==g){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c==h&&d==i&&a==f&&b==g){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(a==f&&b==g&&c==h&&d==i&&((int(e)<=67&&int(j)<=67)||(int(e)>67&&int(j)>67))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(a==f&&b==g&&c==h&&d==i&&((e=='A'&&j=='B')||(e=='B'&&j=='A')||(e=='B'&&j=='C')||(e=='C'&&j=='B')||(e=='D'&&j=='E')||(e=='E'&&j=='D'))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}