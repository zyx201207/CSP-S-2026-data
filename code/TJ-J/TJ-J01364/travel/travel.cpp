#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,r1="0",r2="0",r3="0",r4="0",r="0";
	cin>>c1>>s1>>c2>>s2;
	char a='0',b='0';
	a=s1[2];
	b=s2[2];
	if(c1!=c2){
		cout<<"0000";
	}else{
		r1="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			r2="1";
		}
		if(a=='F'&&b=='D'){
			r3="1";
			r4="1";
		}
		if(a=='A'&&b=='B'){
			r3="1";
			r4="1";
		}
		if(a=='B'&&b=='C'){
			r3="1";
			r4="1";
		}
		if(b=='F'&&a=='D'){
			r3="1";
			r4="1";
		}
		if(b=='A'&&a=='B'){
			r3="1";
			r4="1";
		}
		if(b=='B'&&a=='C'){
			r3="1";
			r4="1";
		}
		if(a=='A'&&b=='C'){
			r3="1";
		}
		if(b=='A'&&a=='C'){
			r3="1";
		}
		if(s1[1]!=s2[1]||s1[0]!=s2[0]){
			r3="0";
			r4="0";
		}
		r=r1+r2+r3+r4;
		cout<<r;
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
