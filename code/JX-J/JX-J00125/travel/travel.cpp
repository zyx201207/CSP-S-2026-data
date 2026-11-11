#include<bits/stdc++.h>
using namespace std;
string s1,s2,a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>a1>>a2;
	bool flag=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=a1[i]) {
			flag=0;
			break;
		}
	}
	if(flag==0) {
        cout<<"0000";
        return 0;
	}
	else cout<<"1";

	flag=1;
	for(int i=0;i<2;i++){
		if(s2[i]!=a2[i]) {
			flag=0;
			break;
		}
	}
	if(flag==0) {
        cout<<"000";
        return 0;
	}
	else cout<<"1";

	if(s2[2]=='A'&&a2[2]=='B'||s2[2]=='A'&&a2[2]=='C'||s2[2]=='B'&&a2[2]=='A'||s2[2]=='B'&&a2[2]=='C'||s2[2]=='C'&&a2[2]=='A'||s2[2]=='C'&&a2[2]=='B'||s2[2]=='D'&&a2[2]=='F'||s2[2]=='F'&&a2[2]=='D'){
	   cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(s2[2]=='A'&&a2[2]=='B'||s2[2]=='B'&&a2[2]=='A'||s2[2]=='B'&&a2[2]=='C'||s2[2]=='C'&&a2[2]=='B'||s2[2]=='D'&&a2[2]=='F'||s2[2]=='F'&&a2[2]=='D'){
	   cout<<"1";
	}
	return 0;
}
