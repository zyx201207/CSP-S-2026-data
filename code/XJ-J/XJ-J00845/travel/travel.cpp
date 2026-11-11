#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[3];
	char b[4],c[4];
	int n;
	cin>>a[1]>>b>>a[2]>>c;
	if(a[1]!="01" && a[1]!="16" && a[2]!="01" && a[2]!="16"){
		if(a[1]==a[2]){
			cout<<"1";
			if(b[0]==c[0] && b[1]==c[1]){
		    	cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"0";
			if(b[0]==c[0] && b[1]==c[1]){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
	}	
	if((b[2]>='A' && b[2]<='C') && (c[2]>='A' && c[2]<='C')){
		cout<<"1";		
	}
	else{
    	cout<<"0";
	}
	cout<<"0";
	return 0;
}
	