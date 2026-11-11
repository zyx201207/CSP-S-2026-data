//贺羿凯，延安市新区第三中学.，SN-J00717 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a=true,b=true,c=true;
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2){
		cout << "1";
	}else{
		cout <<"0000";
		b=false;
	}
	if(b){if(s1[1]==s2[1]){
		cout<<"1";
	}
		else{
		cout << "000";
		c=false;
	}
	if(c){if((s1[2]<=67&&s1[2]>=65)&&(s2[2]<=67&&s2[2]>=65)){
		cout <<"1";
		a=false;
	}
		else if((s1[2]==68||s1[2]==69)&&(s2[2]==68||s2[2]==69)){
			cout <<"1";
			a=false;
	}
	else{
		cout <<"00";
	}
	}
		
	}
	
	if(!a){
		if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
			cout <<"1";}
		else{
			cout <<"0";
		}
	}
	
	
	return 0;
}
