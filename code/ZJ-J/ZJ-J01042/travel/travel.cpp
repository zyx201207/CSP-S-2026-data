#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1=0,f2=0,f30=0,f31=0,f4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1=="01"||c1=="16"||c2=="01"||c2=="16"){
		for(int i=1;i<=4;i++) cout<<0;
	}
	else{
		if(c1==c2) f1=1;
		if(f1==1&&s1[0]==s2[0]&&s1[1]==s2[1]) f2=1;	
		if(f1&&f2){
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) f30=1;
			if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) f31=1;
		}
		if(f1&&f2&&(f30||f31)){
			if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
				f4=1;
			}
		}	
		if(f1==1) cout<<1;
		else cout<<0;
		if(f2==1) cout<<1;
		else cout<<0;
		if(f30==1||f31==1) cout<<1;
		else cout<<0;
		if(f4==1) cout<<1;
		else cout<<0;
	}
	return 0;
}
