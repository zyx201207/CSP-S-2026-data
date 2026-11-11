#include<bits/stdc++.h>
using namespace std;
char s1[5],s2[5];
int main(){
	int c1,c2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(s1[3]<='C'&&s2[3]>='D'){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	if(s1[3]=='A'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='A') cout<<"0";
	else cout<<"1 ";
	return 0;
}
