#include <bits/stdc++.h>
using namespace std;
int main(){
	string c1, s1, c2, s2;
	string c;
	cin>>c1>>s1>>c2>>s2;
	int n=s1.size();
	int p=s2.size();
	int f=0,q=0,e=0;
	if(s1[n-1]=='A' && s2[p-1]=='B' || s1[n-1]=='B' && s2[p-1]=='C' || s1[n-1]=='D' && s2[p-1]=='F'){
		f=1;
	}
	if(s1[n-1]=='A' && s2[p-1]=='C' || s1[n-1]=='C' && s2[p-1]=='A'){
		f=3;
	}
	if(s1[n-2]==s2[n-2]){
		e=1;
	}
	if(c1==c2){
		q=1;
	}
	if(f==1 && q==1 && e==1){
		c="1111";
		cout<<c;
	}else if(q==1 && e==0){
		c="1000";
		cout<<c;
	}else if(q==1 && e==1 && f==0){
		c="1100";
		cout<<c;
	}if(q==1 && e==1 && f==3) {
		c="1110";
		cout<<c;
	}
	if(c1!=c2){
		c="0000";
		cout<<c;
	}	
	return 0;
}
