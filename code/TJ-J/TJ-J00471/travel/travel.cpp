#include <bits/stdc++.h>
using namespace std ;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool t=0;
	if(c1==c2&&c1!="01"&&c2!="01"&&c1!="16"&&c2!="16"){
		cout<<1;
		t=1;
	}
	else{
		cout<<0;
	}
	bool k=0,ce=0;
	if(t&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		k=1;
	}
	else{
		cout<<0;
	}
	if(k&&t){
		if(int(s1[2]-'A')<=2&&int(s2[2]-'A')<=2){
			cout<<1;
			ce=1;
		}
		else if(int(s1[2]-'A')>=3&&int(s2[2]-'A')>=3){
		    cout<<1;
		    ce=1;
		}
		else{
			cout<<0;
		}
	}
	else{
			cout<<0;
	}
	if(k&&t&&ce){
		if(int(s1[2])-1==int(s2[2])){
			cout<<1;
		}
		else if(int(s2[2])-1==int(s1[2])){
			cout<<1;
		}
		else{
			cout<<0;
		}
    }
	else{
		cout<<0;
	}
		
		
	
	
	
	
	return 0;
}
