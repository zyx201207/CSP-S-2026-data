#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1[5],b1[5],a2[5],b2[5];
	bool flag;
	for(int i=0;i<c1.size();i++){
		a1[i]=c1[i]-'0';
		a2[i]=c2[i]-'0';
		if(a1[i]!=a2[i]){
			cout<<"0000";
			return 0;
		}
	}cout<<1;
	for(int i=0;i<s1.size()-1;i++){
		b1[i]=s1[i]-'0';
		b2[i]=s2[i]-'0';
		if(b1[i]!=b2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	int s11,s22;
	int sum=int(s1[2]),sun=int(s2[2]);
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
		s11=1;
		s22=2;
	}
	else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')){
		s11=2;
		s22=1;
	}
	if((s11==1&&s22==2)||(s11==2&&s22==1)){
		cout<<"00";
		return 0;
	}
	if(abs(sum-sun)==1&&(s1[2]!='C'&&s2[2]!='D')&&(s1[2]!='D'&&s2[2]!='C')){
		cout<<11;
		return 0;
	}
	if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')){
		cout<<11;
		return 0; 
	}
	if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
		cout<<10;
		return 0;
	}
	if(abs(sum-sum)!=1||(s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
		cout<<"00";
		return 0;
	}
	return 0;
}
//Trick||Treat! 
