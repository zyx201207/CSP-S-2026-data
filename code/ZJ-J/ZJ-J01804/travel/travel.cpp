#include<bits/stdc++.h>
using namespace std;
string a,c;
char b[5],d[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b[1]>>b[2]>>b[3]>>c>>d[1]>>d[2]>>d[3];
	if(a==c){
		cout<<"1";
		if(b[1]==d[1]&&b[2]==d[2]){
			cout<<"1";
			if((b[3]=='D'&&d[3]=='F')||(b[3]=='F'&&d[3]=='D')){
				cout<<"11";
			}
			else if(b[3]!='D'&&b[3]!='F'&&d[3]!='D'&&d[3]!='F'){
				cout<<"1";
				if(char(b[3]-1)==d[3]||char(b[3]+1)==d[3]){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
