#include <iostream>
using namespace std;
int main(){
	char c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=s1,b=s2;
	if(c1=c2){
		cout<<"1";
		
	}
	else{
		cout<<"0";
		
	}
	for(int i=1;i<=18;i++){
		if(a==b+1){
			cout<<"111";
			break;
		}
		else{
			cout<<"000";
			break;
		}
	}
	return 0;
} 
