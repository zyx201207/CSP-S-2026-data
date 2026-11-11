#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	string a;
	char b[8] = {};
	string c;
	char d[8] = {};
	char x[9] = {};
	cin>>a;
	for(int i = 0;i<3;i++){
		cin>>b[i];
	}
	cin>>c;
	for(int i = 0;i<3;i++){
		cin>>d[i];
	}
	for(int i = 0;i<4;i++){
		x[i] = '0'; 
 	}
	if(a==c){
		x[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			x[1] = '1';
			if((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'&&d[2]!=b[2])){
				x[2] = '1';
				if((b[2] == 'A'||b[2]=='C')&&d[2]=='B'){
					x[3] = '1';
				}else if(b[2] == 'B'&&(d[2]=='A'||d[2]=='C')){
					x[3] = '1';
				}
				for(int i = 0;i<4;i++){
					cout<<x[i];
				}
			}else if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
				x[2] = '1';
				x[3] = '1';
				for(int i = 0;i<4;i++){
					cout<<x[i];
				}
			}else{
				for(int i = 0;i<4;i++){
					cout<<x[i];
				}
			}
		}else{
			for(int i = 0;i<4;i++){
				cout<<x[i];
			}	
		}
	}else{
		for(int i = 0;i<4;i++){
			cout<<x[i];
		}
	}
	
	
	return 0;
}
