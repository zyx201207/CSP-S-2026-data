#include<iostream>
//hello world!
//hello world!
//hello world!
//hello world!
//hello world!
//hello world!
//hello world!
using namespace std;
int qq,ww,ee,rr,tt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,e,f;
	string c,d;
	char g,h;
	cin>>a>>c>>b>>d;
	e = int(c[0])*10+int(c[1]);
	f = int(d[0])*10+int(d[1]);
	g = char(c[2]);
	h = char(d[2]);
	if(a==b){
		cout<<"1";
		if(e==f){
			cout<<1;
			if(g<='c'&&h<='c'||g>='d'&&h>='d'){
				cout<<"1";
				if(g==h+1||h==g+1){
					cout<<"1";
				}
				else if(h=='d'&&g=='f'||h=='f'&&g=='d'){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<"0000";
	return 0;
}
