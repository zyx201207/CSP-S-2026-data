#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1.substr(0,2)==s2.substr(0,2)){
			if(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
				cout<<"1111";
			}
			else if(s1[2]!='D'&&s2[2]!='F'&&s2[2]!='D'&&s1[2]!='F'){
				if(s1[2]=='A'&&s2[2]=='C'||s2[2]=='A'&&s1[2]=='C') cout<<"1110";
				else cout<<"1111";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
