#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[50],s2[50];
int a1=0,a2=0,a3=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	int l1=strlen(s1+1);
	int l2=strlen(s2+1);
	if(c1==c2)cout<<'1',a1=1;
	else cout<<'0';
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a1==1)cout<<'1',a2=1;
	else cout<<'0';
	if(s1[2]<='C'&&s2[2]<='C'&&a1==1&&a2==1){
		a3=1;
		cout<<'1';
	}
	else if(s1[2]>='D'&&s2[2]>='D'&&a1==1&&a2==1){
		a3=1;
		cout<<'1';
	}
	else cout<<'0';
	if((s1[2]==s2[2]+1||s1[2]==s2[2]-1)&&a3==1&&a1==1&&a2==1){
		if(s1[2]=='C'&&s2[2]=='D'){
			cout<<'0';
		}
		else if(s2[2]=='C'&&s1[2]=='D'){
			cout<<'0';
		}
		else cout<<'1';
	}
	else cout<<'0';
	return 0;
}