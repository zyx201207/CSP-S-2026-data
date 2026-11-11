#include <bits/stdc++.h>
using namespace std;
int rc,xc;
char rs,rg,ra,xs,xg,xa;
bool flag[4]={1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>rg>>ra;  
	cin>>xc>>xs>>xg>>xa;  
	if(rc==xc){
		flag[1]=1;
		if(rs==xs && rg==xg){
			flag[2]=1;
		if(ra>='D' && ra<='F' && xa>='D' && xa<='F'){
			flag[3]=1;
			flag[4]=1;
		}
		if(ra>='A' && ra<='C' && xa>='A' && xa<='C'){
			flag[3]=1;
			if(ra=='A' && xa=='B' || xa=='A' && ra=='B' || ra=='B' && xa=='C' || xa=='B' && ra=='C'){
			flag[4]=1;
			}
		}
		
	}
	}       
	
	for(int i=1;i<=4;i++){
		cout<<flag[i];
	}
	return 0;
}