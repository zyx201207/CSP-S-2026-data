#include<bits/stdc++.h> 
using namespace std;
string a1,b1,a2,b2;
bool s1=0,s2=0,s3=0,s4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		s1=1;
		if(b1[0]==b2[0]&&b1[1]==b2[1]){
			s2=1;
			int s=0;
			if((b1[2]=='A'||b1[2]=='B'||b1[2]=='C')&&(b2[2]=='D'||b2[2]=='F')){
				s++;
			}
			if((b2[2]=='A'||b2[2]=='B'||b2[2]=='C')&&(b1[2]=='D'||b1[2]=='F')){
				s+=1;
			}
			if(s==0){
				s3=1;
				if(!((b1[2]=='A'&&b2[2]=='C')||(b2[2]=='A'&&b1[2]=='C'))){
					s4=1;
				}
			}
		} 
	}
	cout<<s1<<s2<<s3<<s4;
	return 0;
}
