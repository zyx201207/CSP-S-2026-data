#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,kg;
int typ,tyc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>c1>>s1>>c2>>s2;
	
	//是否在同一车厢
	if(c1==c2){
		cout<<1;
		tyc=1;
	}
	else {
		cout<<0;
		tyc=0;
	}
	
	//是否在同一节车厢的同一排;
	if(tyc&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		typ=1;
	}else{
		cout<<0;
		typ=0;
	}
	
	//是否在同一节车厢的同一排,且位于过道的同一侧;
	if(tyc==1&&typ==1&&((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D' && s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C'))){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(tyc==1&&typ==1&&((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D' && s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
