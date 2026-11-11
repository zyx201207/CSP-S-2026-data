#include<iostream>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2){
		ans+="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+="1";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				ans+="1";
				char e1,e2;
				if(s1[2]<s2[2])e1=s1[2],e2=s2[2];
				else e1=s2[2],e2=s1[2];
				if((e1=='A'&&e2=='B')||(e1=='B'&&e2=='C')||(e1=='D'&&e2=='F')){
					ans+="1";
				}else{
					ans+="0";
				}
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans="0000";
	}
	cout<<ans<<endl;
	return 0;
}
