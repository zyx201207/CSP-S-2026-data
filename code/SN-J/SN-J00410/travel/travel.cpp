#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,d,b,c;
	string t,f;
	cin>>a>>b>>t>>d>>c>>f;
	if(a==d){
		cout<<"1";
	}else{
		cout<<"0";
	}if(b==c){
		cout<<"1";	
	}else{
		cout<<"0";
	}if(((t=="A"||t=="B"||t=="C")&&(f=="A"||f=="B"||f=="c"))||((t=="D"||t=="F")&&(f=="D"||f=="F"))){
		cout<<"1";	
	}else{
		cout<<"0";
	}if((t=="A"&&f=="B")||(t=="B"&&f=="C")||(t=="C"&&f=="D")||(t=="D"&&f=="F")||(t=="B"&&f=="A")||(t=="C"&&f=="B")||(t=="D"&&f=="C")||(t=="F"&&f=="D")){
		cout<<"1";	
	}else{
		cout<<"0";
	}
	return 0;
}
