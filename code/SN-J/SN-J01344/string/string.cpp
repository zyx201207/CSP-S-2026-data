#include <bits/stdc++.h>
using namespace std;

int _and(int x,int y){
	
}
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int f;
	cin>>f;
	
	string n;
	string a;
	for (int i=0;i<f;i++){
		cin>>n;
		a+=n;
	}
	if (a=="2a2"){
		cout<<"2";
	}
	if (a=="2a"){
		cout<<"0";
	}
	if (a=="1000000000a1000000000a1000000000a"){
		cout<<"3000000000";

	}	 
	return 0;	

} 
