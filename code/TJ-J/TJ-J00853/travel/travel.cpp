#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1=0,a2=0,a3=0,a4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;

	if(c1==c2){
		a1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a2=1;
			if(s1[2]=='A'){
				if(s2[2]=='B'||s2[2]=='C'){
					a3=1;
				}
			}	
			if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C'){
					a3=1;
				}
			}
			if(s1[2]=='C'){
				if(s2[2]=='B'||s2[2]=='A'){
					a3=1;
				}
			}
			if(s1[2]=='D'){
				if(s2[2]=='F'){
					a3=1;
				}
			}
			if(s1[2]=='F'){
				if(s2[2]=='D'){
					a3=1;
				}
			}
			if(s1[2]=='A'){
				if(s2[2]=='B'){
					a4=1;
				}
			}
			if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C'){
					a4=1;
				}
			}
			if(s1[2]=='C'){
				if(s2[2]=='B'){
					a4=1;
				}
			}
			if(s1[2]=='D'){
				if(s2[2]=='F'){
					a4=1;
				}
			}if(s1[2]=='F'){
				if(s2[2]=='D'){
					a4=1;
				}
			}
		}
	}
	
	
	cout<<a1<<a2<<a3<<a4;
} 
