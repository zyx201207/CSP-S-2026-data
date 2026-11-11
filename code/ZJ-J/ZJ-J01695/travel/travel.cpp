#include<bits/stdc++.h>
using namespace std;
#define int long long
string cr,sr,cx,sx;
char s[6]={'0','A','B','C','D','F'};
int nr,nx;
signed main(void){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		if(sr[0]==sx[0] && sr[1]==sx[1]){
			for(int i=1;i<=5;i++){
				if(s[i]==char(sr[2])) nr=i;
				if(s[i]==char(sx[2])) nx=i;
			}
			if((nx<=3&&nr<=3)||(nx>=4&&nr>=4)){
				if(abs(nx-nr)==1) printf("1111");
				else printf("1110");
			}
			else{
				printf("1100");
				return 0;
			}
		} 
		else{
			printf("1000");
			return 0;
		}
	} 
	else{
		printf("0000");
		return 0;
	}
	return 0;
}