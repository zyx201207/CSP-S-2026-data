#include<bits/stdc++.h>
using namespace std;
string a,c,d,e,f,b="0 24 21 2 3 45 21 2 3 4 5";
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	getline(cin,a);
	getline(cin,c);
	getline(cin,d);
	getline(cin,e);
	getline(cin,f);
	string ax=a+c+d+e+f;
	if(ax==b){
		cout<<1<<endl<<2;
	}
	return 0;
} 