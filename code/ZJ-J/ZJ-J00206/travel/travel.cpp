#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string ans="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		ans="0000";
	}
	else{
		char k11=s1[0],k12=s1[1],k21=s2[0],k22=s2[1];
		string k1="",k2="";
		k1+=k11,k2+=k21;
		k1+=k12,k2+=k22;
		if(k1!=k2){
			ans="1000";
		}
		else{
			char st1=s1[2],st2=s2[2];
			if((st1=='A'||st1=='B'||st1=='C')&&(st2=='A'||st2=='B'||st2=='C')){
				if(st1=='B'||st2=='B'){
					ans="1111";
				}
				else{
					ans="1110";
				}
			}
			else if((st1=='D'||st1=='F')&&(st2=='D'||st2=='F')){
				ans="1111";
			}
			else{
				ans="1100";
			}
		}
	}
	cout<<ans;
	return 0;
}