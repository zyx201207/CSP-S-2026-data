#include <bits/stdc++.h>
using namespace std;
int main(){
	freopon("travel.in","r",stdin);
	freopon("travel.out","w",stdout);
	string a,b;
	b={"0"};
	int c=0;
	cin>>c;
	for(int z=0;z<=a.size();z++){
		b=a.length();
	}
	if(b[1]==b[8]){
		cout<<"1";
		if(b[4]==b[11]){
			cout<<"1";
			if(b[5]=='A'||b[5]=='B'||b[5]=='C' && b[12]=='A'||b[12]=='B'||b[12]=='C'){
				cout<<"1";
				if(char(b[5]-b[12])==1 || char(b[12]-b[5])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(b[5]=='D'||b[5]=='F' && b[12]=='D'||b[12]=='F'){
				cout<<"0";
				if(char(b[5]-b[12])==1 || char(b[12]-b[5])==1){
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
	
