#include <iostream>
#include <cstring>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int tt = 1;
	cin >> a>>b>>c>>d;
	if(a==c){
		cout <<"1";
	}
	else{
		cout<<"0";
		tt=0;
		
	} 
	if(b[0]==d[0]&&b[1]==d[1]&&tt==1){
		cout<<"1";
	}
	else{
		cout << "0";
		tt=0;
	} 
	if(b[2]<'D'&&d[2]<'D'&&b[2]!=d[2]&&tt==1){
	
		cout << "1";
	}
	else if (b[2]>='D'&&d[2]<='D'&&b[2]!=d[2]&&tt==1){
		cout << "1";
	}
	else{
		cout << "0";
		tt=0;
	}
	if(b[2] - d[2] == 1 || d[2] - b[2] == 1){
		if(tt==1) cout << "1";
		else cout << "0";
	}
	else cout << "0";
	return 0;
	
	
} 
