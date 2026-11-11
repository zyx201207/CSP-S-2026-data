#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)printf("%d",1);
	else{
		printf("%d%d%d%d",0,0,0,0);
		return 0;
	} 
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		printf("%d",1);
		char a=s1[2],b=s2[2];
		switch(a){
			case 'A':{
				if(b=='B')printf("%d",11);
				else if(b=='C')printf("%d",10);
				else printf("%d%d",0,0);
				break;
			}
			case 'B':{
				if(b=='A'||b=='C')printf("%d",11);
				else printf("%d%d",0,0);
				break;
			}
			case 'C':{
				if(b=='B')printf("%d",11);
				else if(b=='A')printf("%d",10);
				else printf("%d%d",0,0);
				break;
			}
			case 'D':{
				if(b=='F')printf("%d",11);
				else printf("%d%d",0,0);
				break;
			}
			default:{
				if(b=='D')printf("%d",11);
				else printf("%d%d",0,0);
				break;
			}
		}
	}
	else printf("%d%d%d",0,0,0);
	return 0;
} 
