#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool b=0;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<=1;i++){
			if(s1[i]==s2[i]){
			
			}else{
				b=1;
			}
		}
		if(b){
			cout<<0<<0<<0;
			return 0;
		}else{
			cout<<1;
		}
		if(s1[2]=='D'&&s2[2]=='E'){
			cout<<1;
		}
		else if(s1[2]=='E'&&s2[2]=='D'){
			cout<<1;	
		}
		else if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')){
			cout<<1;
		}
		else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
			cout<<1;
		}
		else if(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A')){
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
		if(s1[2]=='C'||s1[2]=='B'||s1[2]=='A'){
			if((s1[2]+1==s2[2]&&s2[2]!='D')||(s1[2]-1==s2[2])){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(s1[2]=='E'||s1[2]=='D'){
			if((s1[2]+1==s2[2])||(s1[2]-1==s2[2]&&s2[2]!='C')){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
	
	
}
