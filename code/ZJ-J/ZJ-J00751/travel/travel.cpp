#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y,px,py;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x=(a[0]-'0')*10+a[1]-'0';
	y=(c[0]-'0')*10+c[1]-'0';
	px=(b[0]-'0')*10+b[1]-'0';
	py=(d[0]-'0')*10+d[1]-'0';
	char xa=b[2],xb=d[2];
	if(x!=y){
		cout<<"0000";
	}
	else{
		cout<<'1';
		if(px!=py){
			cout<<"000";
		}
		else{
			cout<<'1';
			if((xa<='C'&&xb>'C')||(xa>'C'&&xb<='C')){
				cout<<"00";
			}
			else{
				cout<<'1';
				if(abs(xa-xb)==1){
					cout<<'1';
				}
				else cout<<'0';
			}
		}
	}
	return 0;
}