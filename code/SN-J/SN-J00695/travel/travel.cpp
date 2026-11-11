//高易 延安育英中学 SN-J00695 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;int cnt=0;int cntt=0;int ce;int cece;int cnttt;
	if(c1==c2){
		cout<<1;
		cnt=1;
	}
	else{
		cout<<"0000";
	}
	if(cnt==1 and s1[0]==s2[0] and s1[1]==s2[1]){
		cout<<1;cntt=1;
	}else{
		cout<<"000";
	}
	if(cntt==1){
		if(s1[2]>='A' and s1[2]<='C'){
			ce=1;
		}else{
			ce=0;
		}
		if(s2[2]>='A' and s2[2]<='C'){
			cece=1;
		}else{
			cece=0;
		}
		if(ce=cece){
			cout<<1;cnttt=1;
		}else{
			cout<<"00";
		}
	}
	if(cnttt==1){
		if(s1[2]=='C' or s1[2]=='D' and s2[2]=='C' or s2[2]=='D'){
			cout<<'0';
			return 0;
		}
		int a=s1[2];int b=s2[2];
		if(a-b==1 or b-a==1){
			cout<<'1';
		}else{
			cout<<'0';
			}
		
	}
	

	
	
	return 0;
}


