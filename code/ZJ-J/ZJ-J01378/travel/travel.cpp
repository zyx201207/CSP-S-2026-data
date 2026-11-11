#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int n,temp1,temp2;
char s[6]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=4;i++){
		if(s1[2]==s[i]){
			temp1=i;
		}
		if(s2[2]==s[i]){
			temp2=i;
		}
	}
	if(c1==c2){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	n=temp1+temp2;
	if(n==1||n==3||n==7||n==2){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(n==1||n==3||n==7){
		cout<<'1';
	}else{
		cout<<'0';
		return 0;
	}
	return 0;
}
