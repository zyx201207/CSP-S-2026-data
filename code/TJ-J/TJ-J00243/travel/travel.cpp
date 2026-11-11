#include<bits/stdc++.h> 
using namespace std;
int main(){
	char c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=c2)
	{
		if(s1=='01A',s2=='01B'){
		cout<<"1111";
		}
		if(s1=='01C',s2=='01A'){
		cout<<"1110";
		}
		if(s1=='01C',s2=='01D'){
		cout<<"1100";
		}
		if(s1=='02B',s2=='01A'){
		cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}

	return 0;
}
