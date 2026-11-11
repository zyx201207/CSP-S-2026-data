#include<bits/stdc++.h>
using namespace std;
char c1[3],c2[3],s1[3],s2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1=false;
	bool f2=false;
	bool f3=false;
	bool f4=false;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		f1=true;
	}
	if(f1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=true;
		}
	}
	if(f2){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]!='D'&&s2[2]!='F'){
				f3=true;
			}
		}else if(s1[2]=='D'||s1[2]=='F'){
			if(s2[2]!='A'&&s2[2]!='B'&&s2[2]!='C'){
				f3=true;
			}
		}
	}
	if(f3){
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
			f4=true;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
