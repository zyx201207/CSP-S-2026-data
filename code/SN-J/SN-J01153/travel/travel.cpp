#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in" ,"r" ,stdin);
	freopen("travel.out" ,"w" ,stdout);
	char s[4];
	for(int i=0;i<=4;i++){
		cin>>s[i];
	}
	if(s[0]==s[3]) cout<<1;
	else {
		cout<<0000;
		return 0;
	}
	if(s[3]-s[1]==1||s[3]-s[1]==-1) cout<<111;
	else if(s[3]-s[1]==2||s[3]-s[1]==-2) cout<<111;
	else{
		cout<<110;
	}
	return 0;
} 
