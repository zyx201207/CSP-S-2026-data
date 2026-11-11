#include<bits/stdc++.h>
using namespace std;
int travelout;
string c1,c2,c3,c4;
int main(){
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1<<endl;		
	}
	else{
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0;
		return 0;
	}
	if(c2[0]==c4[0]&&c2[1]==c4[1]){
		cout<<1<<endl;		
	}
	else{
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0;
		return 0;
	}
	if(c2[0]==c4[0]&&c2[1]==c4[1]){
		if(c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C'){
				cout<<1<<endl;
		}
		else if(c2[2]=='D'||c2[2]=='F'&&c4[2]=='D'||c4[2]=='F'){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
		if(c2[2]+1==c4[2]||c4[2]+1==c2[2]){
			if(c2[2]=='C'&&c4[2]=='D'){
				cout<<0<<endl;
			}
			else if(c2[2]=='D'&&c4[2]=='C'){
				cout<<0<<endl;
			}
			else{
				cout<<1<<endl;
			}
		}
		else{
			cout<<0;
		}
	}

	return 0; 
}	
