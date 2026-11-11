#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s;
int a1,a2,a3,a4; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		 a1=1;
		 if(s1[0]==s2[0]&&s1[1]==s2[1]){
			 	a2=1;
			 	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
					if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
						a3=1;
						if(s1[2]-1==s2[2]||s1[2]+1==s2[2]) a4=1;
					}
							
				}
			 	else if(s1[2]=='D'||s1[2]=='F'){
					if(s2[2]=='D'||s2[2]=='F'){
						a3=a4=1;
					}
					
				}
		}
	}
	a1=char(a1);
	a2=char(a2);
	a3=char(a3);
	a4=char(a4);
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
