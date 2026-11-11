#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	char q,w,e,r,t,y;
	cin>>a>>q>>w>>e>>b>>r>>t>>y;
	if(a==b){
		cout<<"1";
		if(q==r&&w==t){
		cout<<"1";
			if(e+y<=133||e+y==137){
				cout<<"1";
				if((e+y)%2==1)	cout<<"1";
				else	cout<<"0";
			}else	cout<<"00";
		}else	cout<<"000";
	}else	cout<<"0000";
return 0;}