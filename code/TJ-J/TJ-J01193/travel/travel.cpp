#include <iostream>
#include <string>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=max(s1[2],s2[2]);
	int b=min(s1[2],s2[2]);
	if(c1=="02"&&c2=="02"){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}	
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
    	cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(a-b>2||a==68&&b==67){
    	cout<<"00";
		return 0;
	}
	else {
		cout<<"1";
		
	}
	if(a-b==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	
	
	return 0;
}
