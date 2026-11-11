//马知遥 西安交通大学附属中学 SN-J00651 
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cai,sai,cbi,sbi,ps;
	bool flag1,flag2,flag3,flag4;
	cin>>cai>>sai>>cbi>>sbi;
	if(cai==cbi){
		cout<<1;
		flag1=1;
	}
	else{
		cout<<0;
		flag1=0;
	}
	flag2=1;
	for(int i=0;i<sai.size()-1;i++){
		if(sai[i]!=sbi[i]){
			flag2=0;
			break;
		}
	}
	if(flag2 && flag1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	char zb,yb;
	if(sai[sai.size()-1]=='A' || sai[sai.size()-1]=='B' || sai[sai.size()-1]=='C'){
		zb='#';
	}
	else{
		zb='$';
	}
	if(sbi[sbi.size()-1]=='A' || sbi[sbi.size()-1]=='B' || sbi[sbi.size()-1]=='C'){
		yb='#';
	}
	else{
		yb='$';
	}
	if((zb==yb) && flag2 && flag1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	char a=sai[sai.size()-1],b=sbi[sbi.size()-1];
	if(abs(a-b)==1 && (zb==yb) && flag2 && flag1){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
