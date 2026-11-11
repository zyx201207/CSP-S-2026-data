#include <bits/stdc++.h>
using namespace std;
string s1[105],s2[105];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1;
	cin>>c2>>s2;
	int f1=0,f2=0,f3=0,f4=0;
	if(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16"){
		f1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=1;
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				f3=1;
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
				    f4=1;
			    }
			}		
            else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
            	f3=1;
            	if(s1[2]-s2[2]==2||s2[2]-s1[2]==2){
				    f4=1;
			    }
			}	
		}
	}
	if(f4==1){
		cout<<"1111";
		return 0;
	}
	if(f3==1&&f4==0){
		cout<<"1110";
		return 0;
	}
	if(f2==1&&f3==0){
		cout<<"1100";
		return 0;
	}
	if(f1==1&&f2==0){
		cout<<"1000";
		return 0;
	}
	if(f1==0){
		cout<<"0000";
		return 0;
	}
	return 0;
}
