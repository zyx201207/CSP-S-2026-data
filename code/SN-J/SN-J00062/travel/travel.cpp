#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(int(c1)!=int(c2)){
		cout<<"0000";
	}else if(int(s1)-256==int(s2) || int(s1)+256==int(s2)){
		cout<<"1000";
	}else if(s1>s2){
		if((int(s1)-int(s2))<256)
			cout<<"1100";
	}else if(s2>s1){
		if((int(s2)-int(s1))<256)
			cout<<"1100";
	}else if(int(s1)-1!=int(s2) || int(s1)+1!=int(s2)){
		cout<<"1110";
	}else if(s1>s2){
		if((int(s1)-int(s2))==1)
			cout<<"1111";
	}else if(s2>s1){
		if((int(s2)-int(s1))==1)
			cout<<"1111";
	}
	
	return 0;
}
