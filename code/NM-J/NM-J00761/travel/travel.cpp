#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0;
	int b=0;
	string c;
	string d;
	cin>>a>>c>>b>>d;
	int e=0;
	e=(c[0]-'0')*10+c[1]-'0'; 
	int f=0;
	f=(d[0]-'0')*10+d[1]-'0';
	int g=0;
	int h=0;
	g=c[2]-'A';
	h=d[2]-'A';
	if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(e==f){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(g<3&&h<3||g>=3&&h>=3){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((g-h)==1||(h-g)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
} 
