#include<iostream>
using namespace std;
int c1,s1,c2,s2;
int main() {
	cin>>c1>>s1>>c2>>s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(s1==s2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1==s2&&s1-s1==s2-s2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1==s2&&s1-s1==s2-s2&&s1-1==s2&&s+1==s2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1==s2&&s1-s1==s2-s2&&s1-1==s2&&s+1==s2&&s1+1==s2&&s1-1==s2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
}
