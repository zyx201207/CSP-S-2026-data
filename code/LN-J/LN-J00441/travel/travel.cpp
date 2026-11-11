#include<bits/stdc++.h>
using namespace std;
int t1=0,t2=0,t3=0;
int main(){
	//别忘
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	//step1
	if(c1==c2){
		cout<<1;
		t1=1;
	}
	else cout<<0;
	//step2
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&t1==1){
		cout<<1;
		t2=1;
	}
	else cout<<0;
	//step 3
	if((s1[2]<='C'&&s2[2]<='C')&&t2==1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			t3=1;
		}
	}
	else if(((s1[2]<='F'&&s1[2]>='D')&&(s2[2]<='F'&&s2[2]>='D'))&&t2==1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			t3=1;
		}
	}else cout<<0;
	//step4
	if((s1[2]=='A'&&s2[2]=='B')&&t3==1)cout<<1;
	else if((s1[2]=='B'&&s2[2]=='A')&&t3==1)cout<<1;
	else if((s1[2]=='C'&&s2[2]=='B')&&t3==1)cout<<1;
	else if((s1[2]=='B'&&s2[2]=='C')&&t3==1)cout<<1;
	else if((s1[2]=='D'&&s2[2]=='F')&&t3==1)cout<<1;
	else if((s1[2]=='F'&&s2[2]=='D')&&t3==1)cout<<1;
	else cout<<0;
	return 0;
}
