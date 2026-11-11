#include<iostream>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
	    cout<<"1";
    }
    else{
    	cout<<"0";
	}
	if(b==d){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c==a){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(d==b){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
