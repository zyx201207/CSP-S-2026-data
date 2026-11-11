#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
string s1,s2,s3,s4;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	a=(int(s1[0])-'0')*10+int(s1[1])-'0';
	c=(int(s3[0])-'0')*10+int(s3[1])-'0';
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	string x=" ";
	x+=char(min(int(s4[2]),int(s2[2])));
	x+=char(max(int(s4[2]),int(s2[2])));
	if((x==" AB")||(x==" AC")||(x==" BC")||(x==" DF")){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	
	if((x==" AB")||(x==" BC")||(x==" DF")){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}