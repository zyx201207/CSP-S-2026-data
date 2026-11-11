#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string a,b,c,d;
int e,f,g,h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	e=(b[0]-'0')*10+(b[1]-'0');
	f=b[2]-'A'+1;
	g=(d[0]-'0')*10+(d[1]-'0');
	h=d[2]-'A'+1;
	if (a==c){
		cout<<1;
		if (e==g){
			cout<<1;
			if (f<=3 && h<=3){
				cout<<1;
				if (f-h==1 || h-f==1){
					cout<<1;
				}
				else {
					cout<<0;
				}
			}
			else if ((f==4 && h==6) || (f==6 && h==4)){
				cout<<1<<1;
			}
			else {
				cout<<0<<0;
			}
		}
		else {
			cout<<0<<0<<0;
		}
	}
	else {
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
