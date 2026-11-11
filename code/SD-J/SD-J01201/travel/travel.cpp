#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
char x[5],y[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>a>>b>>c>>d;
	if (a==c){
		cout <<"1";
		x[0]=b[0],x[1]=b[1];
		y[0]=d[0],y[1]=d[1];
		if (x[0]==y[0]&&x[1]==y[1]){
			cout <<"1";
			char e=b[2],f=d[2];
			if ((e<='C'&&f<='C')||(e>='D'&&f>='D')){
				cout <<"1";
				int p=e-f;
				if (abs(p)==1) cout <<"1";
				else cout <<"0";
			}else cout <<"00";
		}else cout <<"000";
	}
	else cout <<"0000";
	return 0;
}
