#include<iostream>
#include<fstream>
#include<string>

using namespace std;
string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]+b[1]==d[0]+d[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(b[2]-d[2]==1||b[2]-d[2]==-1){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
