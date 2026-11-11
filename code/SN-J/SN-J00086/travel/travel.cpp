#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,n1;
	string s,s1;
	cin>>n>>s>>n1>>s1;
	bool b1=true,b2=true,b3=false,b4=false,c=false,c1=false;
	if(n!=n1){
		b1=false;
		b2=false;
		b3=false;
		b4=false;
		cout<<b1<<b2<<b3<<b4;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[0]!=s1[0] || s[1]!=s1[1]){
			b2=false;
			b3=false;
			b4=false;
			cout<<b1<<b2<<b3<<b4;
			return 0;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[2]=='F' || s[2]=='D'){
			c=true;
		}
	}
	for(int i=0;i<s1.size();i++){
		if(s1[2]=='F' || s1[2]=='D'){
			c1=true;
		}
	}
	if(c==c1==1){
		b3=true;
	}
	for(int i=0;i<s.size();i++){
		if(s[2]=='A' and s1[2]=='B' || s[2]=='B' and s1[2]=='A'){
			b4=true;
		}else if(s[2]=='C' and s1[2]=='B' || s[2]=='B' and s1[2]=='C'){
			b4=true;
		}else if(s[2]=='F' and s1[2]=='D' || s[2]=='D' and s1[2]=='F'){
			b4=true;
		}
	}
	
	cout<<b1<<b2<<b3<<b4;
	return 0;
} 
