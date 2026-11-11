#include<bits/stdc++.h>
using namespace std;
int a,b;
char c1,s1,c2,s2
int main(){
	a=0;
	freopen("travel.in","r",stdin)
	freopen("travel.out","w",stdout)
	int s='s1'-1;
	int m='s1'+1;
	cin>>c1,s1,c2,s2;
	if(c1==c2){
		cout <<"1";
		if (s==s2||m==s2){
			cout<<"1";
			a=1;
		}else {
			cout <<"0";
		}
		cout<<"1";
		if (a==1){
			cout<<"1";
		}else {
			cout<<"0"
		}			
		
		
	}else {
		cout <<"0";
		if (s==s2||m==s2){
			cout<<"1";
			a=1;
		}else {
			cout <<"0";
		}
		cout<<"1";
		if (a=1){
			cout<<"1";
		}else {
			cout<<"0"
		}			
	}
}

