#include <iostream>
using namespace std;
int a1,b1;
char a2[5],b2[5]; 
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2[1]>>a2[2]>>a2[3]>>b1>>b2[1]>>b2[2]>>b2[3];
	if(a1==b1){
		cout<<'1';
		if(a2[1]==b2[1]&&a2[2]==b2[2]){
			cout<<'1';
			if(((a2[3]=='A'||a2[3]=='B'||a2[3]=='C')&&(b2[3]=='A'||b2[3]=='B'||b2[3]=='C'))||((a2[3]=='D'||a2[3]=='F')&&(b2[3]=='D'||b2[3]=='F'))){
				cout<<'1';
				if(a2[3]-b2[3]==1||b2[3]-a2[3]==1||(a2[3]=='D'&&b2[3]=='F')||(a2[3]=='F'&&b2[3]=='D')){
					cout<<'1';
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
