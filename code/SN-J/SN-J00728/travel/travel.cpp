//宋璇章-西安交通大学附属中学-SN-J00728
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(((s1[2]<68)&&(s2[2]<68))||((s1[2]>='D')&&(s2[2]>='D'))){
				cout<<"1";
				if(((s1[2]!=68)&&(s2[2]!=68)&&((s1[2]-1==s2[2])||(s2[2]-1==s1[2])))||((s1[2]=68&&s2[2]==70)||(s2[2]==68&s1[2]==70))){
					cout<<"1";
				}	
				else{
					cout<<"0";
				}				
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}	
	return 0; 
}
