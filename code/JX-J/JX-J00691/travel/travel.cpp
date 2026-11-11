#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool la=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		la=1;
	}else{
	cout<<0;
	la=0;
    }
    
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(la==1){
			cout<<1;
			la=1;
		}else{
			cout<<0;
			la=0;
		}
	}else{
		cout<<0;
		la=0;
	}
	
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]!='D'&&s2[2]!='F'){
			if(la==1){
				cout<<1;
				la=1;
			}else{
				cout<<0;
				la=0;
			}
		}else{
			cout<<0;
			la=0;
		}
	}else{
	   if(s2[2]=='D'||s2[2]=='F'){
		   if(la==1){
		   cout<<1;
		   la=1;
		   }else{
				cout<<0;
				la=0;
			}
	   }else{
		   cout<<0;
		   la=0;
	   }
	}
	if((s1[2]==char(s2[2]+1)&&s2[2]!='C')||(s1[2]==char(s2[2]-1)&&s2[2]!='D')){
		if(la==1){
		cout<<1;
		la=1;
		}else{
			cout<<0;
			la=0;
		}
	}else{
		cout<<0;
		la=0;
	}
return 0;
}
