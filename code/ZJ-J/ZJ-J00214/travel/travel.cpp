#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int flat1,flat2,flat3,flat4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){flat1=0;flat2=0;flat3=0;flat4=0;
	}else if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		flat1=1;flat2=0;flat3=0;flat4=0;
	}else if(!(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))){
		flat1=1;flat2=1;flat3=0;flat4=0;
	}else if(s1[2]=='D'||s1[2]=='F'){
		flat1=1;flat2=1;flat3=1;flat4=1;
	}else if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'){
		flat1=1;flat2=1;flat3=1;flat4=1;
	}else{
		flat1=1;flat2=1;flat3=1;flat4=0;
	}
	cout<<flat1<<flat2<<flat3<<flat4;
	
	return 0;
}