#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freoprn("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(b[2]=='A'||b[2]=='B'){
				if(d[2]=='A'||d[2]=='B'){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
			}
			else if(b[2]=='C'||b[2]=='D'||b[2]=='E'){
				if(d[2]=='C'||d[2]=='D'||d[2]=='E'){
					cout<<"1";
					if(b[2]=='D'){
						cout<<"1";
					}
					else if(b[2]=='E'&&d[2]=='C'){
						cout<<"0";
					}else if(b[2]=='C'&&d[2]=='E'){
						cout<<"0";
					}
					else{
						cout<<"1";
					}
				}
				else{
					cout<<"00";
				
			}
		}
		else{
			cout<<"000";
		}
	}}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	flcose(stdout);
	return 0;
}