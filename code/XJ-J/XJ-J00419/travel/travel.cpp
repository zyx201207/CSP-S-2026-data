#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int f1=0;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	int flag=0,f=1;
	if(s1[1]+s1[0]==s2[1]+s2[0]){
		cout<<1;
	}
	else{
		f=0,f1=1;
		cout<<"000";
	}
	if(f==1){
		if(s1[2]+s2[2]<='C'+'C'){
			flag=1;
		}
		if(s1[2]=='D' || s1[2]=='F' && s2[2]=='D' || s2[2]=='F'){
			flag=1;
		}
		if(flag==1){
			cout<<1;
		}
		else{
			cout<<0;
		}	
	}
	if(f1==1){
		return 0;
	}
	if(f==1 && flag==1){
		if(s1[2]+1==s2[2] || s1[2]-1==s2[2]){
			cout<<1;
			return 0;
		}
	}
	if(s1[2]+1!=s2[2] || s1[2]-1!=s2[2]){
		cout<<0;
	}
	return 0;
}
