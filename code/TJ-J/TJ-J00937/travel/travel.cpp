#include <bits/stdc++.h>
using namespace std;
bool f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s1,s2,t1,t2;
	cin>>s1>>t1>>s2>>t2;
	if(s1!=s2){
		printf("%s","0000");
		return 0;
	} 
	else{
		for(int i=0;i<2;i++){
			if(t1[i]!=t2[i]){
				printf("%s","1000");
				return 0;a
			}
		}
		if((t1[2]=='A'&&t2[2]=='B')||(t1[2]=='B'&&t2[2]=='C')||(t1[2]=='D'&&t2[2]=='F')||(t1[2]=='B'&&t2[2]=='A')||(t1[2]=='C'&&t2[2]=='B')||(t1[2]=='F'&&t2[2]=='D')){
			f1=1;
		}
		if((t1[2]=='A'&&t2[2]=='B')||(t1[2]=='A'&&t2[2]=='C')||(t1[2]=='B'&&t2[2]=='C')||(t1[2]=='D'&&t2[2]=='F')){
			f2=1;
		}	
		if((t1[2]=='B'&&t2[2]=='A')||(t1[2]=='C'&&t2[2]=='A')||(t1[2]=='C'&&t2[2]=='B')||(t1[2]=='F'&&t2[2]=='D')){
			f2=1;
		}	
	}
	if(f1&&f2) printf("%s","1111");
	else if(f1==0&&f2==0) printf("%s","1100");
	else printf("%s","1110");
	return 0;
}
