#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1[3],s2[3];
	int x[4];
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		x[0]=1;
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			x[1]=1;
			if((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C')){
				if((s2[2]=='A')||(s2[2]=='B')||(s2[2]=='C')){
					x[2]=1;
				}
			}
			if((s1[2]=='D')||(s1[2]=='F')){
				if((s2[2]=='D')||(s2[2]=='F')){
					x[2]=1;
				}
			}
		}
	}
	if(c1==c2){
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			if((s1[2]=='A')&&(s2[2]=='B')){
			x[3]=1;
		}
			if((s1[2]=='B')&&(s2[2]=='A')){
			x[3]=1;
		}
		if((s1[2]=='B')&&(s2[2]=='C')){
			x[3]=1;
		}
		if((s1[2]=='C')&&(s2[2]=='B')){
			x[3]=1;
		}
		if((s1[2]=='D')&&(s2[2]=='F')){
			x[3]=1;
		}
		if((s1[2]=='F')&&(s2[2]=='D')){
			x[3]=1;
		}
	}
}
	for(int i=0;i<4;i++){
		if(x[i]!=1) x[i]=0;
		cout<<x[i];
	}
	return 0;
}
