#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char c1[105],c2[105];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool flag=1;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			flag=0;
			break;
		}
	}
	if(flag==0){
		cout<<"0000";
		return 0;
	}
	flag=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			flag=0;
			break;
		}
	}
	if(flag==0){
		cout<<"1000";
		return 0;
	}
	flag=1;
	if((s1[2]-'A'<3&&s2[2]-'A'<3)||(s1[2]-'A'>=3&&s2[2]-'A'>=3)){
		cout<<"111";
		int a=s1[2]-'A'+1;
		int b=s2[2]-'A'+1;
		if(abs(a-b)==1||(a==4&&b==6||a==6||b==4)){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<"1100";
		return 0;
	}
	return 0;
} 
