#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s+='1';
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		a+=s1[i];
	}
	for(int i=0;i<2;i++){
		b+=s2[i];
	}
	if(a==b){
		s+='1';
	}else{
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='C'&&s2[2]=='D'){
		s+='0';
	}
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')){
		s+='1';
		if((s1[2]+1==s2[2])||(s2[2]+1==s1[2])){
			s+='1';
		}else{
			s+='0';
		}
	}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		s+='1';
		s+='1';
	}else{
		s+='0';
	}
	cout<<s;
	return 0;
} 
