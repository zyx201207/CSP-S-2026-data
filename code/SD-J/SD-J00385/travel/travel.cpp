#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	int c=s1[2]-'A',d=s2[2]-'A';
	if((c<=2&&d<=2)||(c>=3&&d>=3)){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(c-d)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
