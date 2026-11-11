#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="";
long long s3[10],s4[10];
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	s3[1]=s1[0]-'0';
	s3[2]=s1[1]-'0';
	s3[3]=s1[2]-'A'+1;
	s4[1]=s2[0]-'0';
	s4[2]=s2[1]-'0';
	s4[3]=s2[2]-'A'+1;
//	cout<<s3[3]<<" "<<s4[3]<<" ";
	if(c1==c2){
		if(s3[1]==s4[1]&&s3[2]==s4[2]){
			if(((s3[3]==1||s3[3]==2||s3[3]==3)&&(s4[3]==1||s4[3]==2||s4[3]==3))||((s3[3]==4||s3[3]==6)&&(s4[3]==4||s4[3]==6))){
				if((s3[3]+1==s4[3]||s3[3]-1==s4[3])||s3[3]+s4[3]==10){
					ans="1111";
				}else{
					ans="1110";
				}
			}else{
				ans="1100";
			}
			
		}else{
			ans="1000";
		}
	}else ans="0000";
	cout<<ans;
	return 0;
} 
