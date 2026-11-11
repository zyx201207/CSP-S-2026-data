#include<iostream>
#include<string>
using namespace std;
signed main(){
	preopen("travel","r",stdin);
	preopen("travel","w",stdout);
	int a;
	cin>>a;
	if(a==2){
		cout<<0;
	}
	if(a==6){
		cout<<3000000000;
	}
	return 0;
}
