#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s_1,c_1,s_2,c_2;
	cin>>s_1>>c_1>>s_2>>c_2;
	if(s_1!=s_2){
		cout<<"0000";
		return 0;
	}
	else if(c_1[0]!=c_2[0]||c_1[1]!=c_2[1]){
		cout<<"1000";
		return 0;
	}
	else if((c_1[2]<='C'&&c_2[2]>'C')||(c_1[2]>'C'&&c_2[2]<='C')){
		cout<<"1100";
		return 0;
	}
	else if((c_1[2]+1)!=c_2[2]&&(c_1[2]-1)!=c_2[2]){
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
		return 0;
	}
	return 0;
} 
