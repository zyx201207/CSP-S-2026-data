#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rcx,xcx;
	string rzw,xzw;
	cin>>rcx>>rzw>>xcx>>xzw;
	int tcx1=0,typ2=0,tyc3=0,txl4=0;
	if(rcx==xcx){
		tcx1=1;
		if(rzw[0]==xzw[0]&&rzw[1]==xzw[1]){
			typ2=1;
			if(typ2==1&&((rzw[2]=='A'||rzw[2]=='B'||rzw[2]=='C')&&(xzw[2]=='A'||xzw[2]=='B'||xzw[2]=='C'))||((rzw[2]=='D'||rzw[2]=='F')&&(xzw[2]=='D'||xzw[2]=='F'))){
				tyc3=1;
				if(typ2==1&&((rzw[2]=='C'&&xzw[2]=='B')||(rzw[2]=='B'&&xzw[2]=='C')||(rzw[2]=='A'&&xzw[2]=='B')||(rzw[2]=='B'&&xzw[2]=='A')||((rzw[2]=='D'||rzw[2]=='F')&&(xzw[2]=='D'||xzw[2]=='F')))){
					txl4=1;
				}
			}
	    }
	}


	
	cout<<tcx1<<typ2<<tyc3<<txl4;
	return 0;
}

