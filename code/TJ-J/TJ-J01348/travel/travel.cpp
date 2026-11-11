#include<bits/stdc++.h>
using namespace std;
bool samelist(char a,char b){
	if((a=='D'&&b=='F')||(b=='D'&&a=='F')){
		return 1;
	}else if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	ifstream ci("travel.in");
	ofstream co("travel.out");
	string x1,x2,y1,y2;
	ci>>x1>>x2>>y1>>y2;
	if(x1!=y1)co<<"0000";
	else{
		co<<"1";
		if(x2[0]+x2[1]!=y2[0]+y2[1]){
			co<<"000";
		}else{
			co<<"1";
			if(!samelist(x2[2],y2[2])){
				co<<"00";
			}else{
				co<<"1";
				if((x2[2]=='D'&&y2[2]=='F')||(y2[2]=='D'&&x2[2]=='F')||x2[2]-y2[2]==1||y2[2]-x2[2]==1){
					co<<"1";
				}else{
					co<<"0";
				}
			}
		}
	}
	return 0;
}
