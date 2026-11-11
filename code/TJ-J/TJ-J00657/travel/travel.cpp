#include<bits/stdc++.h>
using namespace std;
int a[3];
char b[3][3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i]>>b[i][0]>>b[i][1]>>b[i][2];
	}
	if(a[1]==a[2]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[1][1]==b[2][1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((b[1][2]=='A'&&b[2][2]=='B')||(b[1][2]=='B'&&b[2][2]=='A')||
	   (b[1][2]=='B'&&b[2][2]=='C')||(b[1][2]=='C'&&b[2][2]=='B')||
	   (b[1][2]=='D'&&b[2][2]=='F')||(b[1][2]=='F'&&b[2][2]=='D'))
		cout<<"11";
	else if((b[1][2]=='A'&&b[2][2]=='C')||(b[1][2]=='C'&&b[2][2]=='A'))
		cout<<"10";
	else cout<<"00";	
	return 0;
} 
