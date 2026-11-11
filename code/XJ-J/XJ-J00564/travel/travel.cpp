#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
}