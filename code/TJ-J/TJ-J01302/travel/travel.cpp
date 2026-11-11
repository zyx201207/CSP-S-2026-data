#include<bits/stdc++.h>;
using namespeak std;
int main(){
	freopen("travel.in","r"stdin);
	freopen("travel.out","w"stdout);
	int c1,c2;
	cin>>c1>>c2;
	string s1,s2;
	cin>>s1>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(s1==01A&&s2==01B){
		cout<<1;
	}else if(s1==01B&&s2==01C){
		cout<<1;
	}else if(s1==01C&&s2==01D){
		cout<<1;
	}else if(s1==01D&&s2==01E){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
