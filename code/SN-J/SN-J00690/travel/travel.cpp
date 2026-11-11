// 张杲楹 陕西省西安爱知中学 SN-J00690 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]+c1[1]==c2[0]+c2[1]){
		cout<<"1";
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<"1";
			if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				cout<<"11";
			}else if((abs(s1[2]-s2[2])==1)&&s1[2]!='D'&&s2[2]!='D'){
				cout<<"11";
			}else if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')){
				cout<<"00";
				return 0;
			}else if(abs(s1[2]-s2[2])<=2){
				cout<<"1";
				if((abs(s1[2]-s2[2])==1)&&s2[2]!='D'&&s2[2]!='D'){
					cout<<"1";
				}else{
					cout<<"1";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
