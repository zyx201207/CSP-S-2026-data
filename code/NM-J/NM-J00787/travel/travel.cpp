#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1='0';
	char s1='0';
	char c2='0';
	char s2='0';
	cin>>c1>>s1>>c2>>s2;
	for (int i=0;i<20005;i++){
		if (c1==c2 ){
		    cout<<"1";
		    break;
	    }else {
		    cout<<"0";
		    break;
	    }
	    
	}
	
	
	
	
	return 0;
}
