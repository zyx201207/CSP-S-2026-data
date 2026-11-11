#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int e;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}if((s1[2]>=65&&s1[2]<=67&&s2[2]<=67&&s2[2]>=65)||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		e=1;
		cout<<1;
	}else{
		e=0;
		cout<<00;
	if(s2[2]=='D'&&s1[2]=='C'){
		cout<<0;
	}
	}if(e==1&&s1[2]=='D'||s1[2]-1==s2[2]||s1[2]+1==s2[2]){
		cout<<1;
	}else{
		cout<<0;
	}
}
