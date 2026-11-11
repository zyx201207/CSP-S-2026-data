#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string d,e;
	int a,b,c,f;
	cin>>a>>b>>d>>c>>f>>e;
	if(a==c){
		cout<<"1";
		if(b==f){
		cout<<"1";
		if(d=="A"&&e=="B"||d=="A"&&e=="C"||d=="B"&&e=="C"||d=="B"&&e=="A"||d=="C"&&e=="A"||d=="C"&&e=="B"){
		cout<<"1";
		if(d=="A"&&e=="B"||d=="B"&&e=="A"){
		cout<<"1";
	}
	else{
		if(d=="C"&&e=="B"||d=="B"&&e=="C"){
		cout<<"1";
	}
		else{
			if(d=="D"&&e=="F"||d=="F"&&e=="D"){
		cout<<"1";
	}
		else{
		cout<<"0";}}
	}
	}
	else{
		if(d=="D"&&e=="F"||d=="D"&&e=="F"){
			cout<<1;
		}else{
		
		cout<<"00";}
	}
	
	}
	else{
		cout<<"000";
	}
	}
	else{
		cout<<"0000";
	}return 0;
} 

