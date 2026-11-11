#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,s1,c2,s2;
	cin>>c1>>s1;
	cin>>c2>>s2;
	int c=s1-'A';
	int d=s2-'A';
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(abs(d-c)<=5&&c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((c<=1&&d<=1||c>1&&d>1)&&abs(d-c)<=5&&c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(abs(b-a)==1&&c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
