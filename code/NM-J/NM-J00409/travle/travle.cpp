#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<s1.length();i=i+2){
			if(s1[i]<='9' && s1[i]>='0' && s2[i]<='9' && s2[i]>='0'){
				if(s1[i]==s2[i]){
					cout<<"1";
						if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C') || (s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F')){
							cout<<"1";
							if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='F')){
								cout<<"1";
							}else{
								cout<<"0";
							}
						}else{
							cout<<"00";
						}
				}else{
					cout<<"000";
				}
			}
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
