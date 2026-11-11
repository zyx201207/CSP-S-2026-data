#include<bits/stdc++.h>
using namespace std;
char s1[15],s2[15],s3[15],s4[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",s1+1,s2+1,s3+1,s4+1);
	if(s1[1]==s3[1]&&s1[2]==s3[2]){
		cout<<"1";
		if(s2[1]==s4[1]&&s2[2]==s4[2]){
			cout<<"1";
			char pos1,pos2;
			for(char i='A';i<='E';i++){
				if(s2[3]==i) pos1=i;
				if(s4[3]==i) pos2=i;
			}
			if(!((pos1<='C')^(pos2<='C'))){
				cout<<"1";
				if((pos1=='C'&&pos2=='D')||(pos2=='C'&&pos1=='D')||abs(pos1-pos2)!=1) cout<<"0";
				else cout<<"1";
			}
			else cout<<"00";
		}	
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
