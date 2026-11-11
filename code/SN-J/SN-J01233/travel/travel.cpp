#include<bits/stdc++.h>
using namespace std ;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int f=0;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]){
			f=0;	
		}else f=1;
	}
	if(f==1){
		cout<<0;
			cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	else cout<<1;
	f=0;
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			f=0;	
		}else f=1;
	}
	if(f==1){
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	else cout<<1;
	if(((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s2[2]=='D'||s2[2]=='F')&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'))){
			cout<<0;
			cout<<0;
			return 0;
		}else if(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
			cout<<11;
			return 0;
		}else{
			if(s1[2]=='A'&&s2[2]=='C'||s2[2]=='A'&&s1[2]=='C'){
				cout<<10;
			}else cout<<11;
			return 0;
		}
	return 0;
}
