#include<bits/stdc++.h>
using namespace std;
string sr,srr,sx,sxx,snb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>sr>>srr>>sx>>sxx;
	if(sr==sx){
		snb+='1';
		if(srr[0]+srr[1]==sxx[0]+sxx[1]){
		snb+='1';
		
		}
		else snb+='0';
		if(srr[0]+srr[1]==sxx[0]+sxx[1]){
			if( ((srr[2]=='D'||srr[2]=='F')&&(sxx[2]=='D'||sxx[2]=='F'))||((srr[2]=='A'||srr[2]=='B'||srr[2]=='C')&&(sxx[2]=='A'||sxx[2]=='B'||sxx[2]=='C'))){
				snb+='1';
				if((abs(srr[2]-sxx[2])==1||((srr[2]=='D'||srr[2]=='F')&&(sxx[2]=='D'||sxx[2]=='F')))&&(srr[2]+sxx[2]!='C'+'D')){
					snb+='1';
				}
				else snb+='0';
			}
			else{
				snb+="00";
			
			}
		}
		else{
		snb+="00";
		}
		
	}
	else {
		cout<<"0000";
	}
	

	cout<<snb;
	return 0;
} 
