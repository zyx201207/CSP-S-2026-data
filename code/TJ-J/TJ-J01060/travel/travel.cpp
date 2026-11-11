#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
	}else {
		cout<<"0000";
		return 0;
	}
	int x=int(b[0]-'0')*10+int(b[1]-'0');
	int y=int(d[0]-'0')*10+int(d[1]-'0');
	if(x==y){
		cout<<'1';
	}else {
		cout<<"000";
		return 0;
	}
	int xa=b[2]-'A';
	int ya=d[2]-'A';
	if(xa<=2&&ya<=2){
		cout<<'1';
		if(xa>ya){
			if(xa-ya==1){
				cout<<'1';
			}else {
				cout<<'0';
			}
		}else if(xa<ya){
			if(ya-xa==1){
				cout<<'1';
			}else {
				cout<<'0';
			}
		}
	}else if(xa>2&&ya>2){
		cout<<"11";
		return 0;
	}else {
		cout<<"00";
		return 0;
	}
	return 0;
}
