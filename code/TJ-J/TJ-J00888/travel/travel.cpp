#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int st1=0,st2=0,ct1=0,ct2=0;
	for(int i=0;i<2;i++){
		ct1=ct1*10+(c1[i]-'0');
	}
	for(int i=0;i<2;i++){
		ct2=ct2*10+(c2[i]-'0');
	}
	for(int i=0;i<2;i++){
		st1=st1*10+(s1[i]-'0');
	}
	for(int i=0;i<2;i++){
		st2=st2*10+(s2[i]-'0');
	}
	bool ok1=0,ok2=0;
	if(s1[2]-'A'<3&&s2[2]-'A'<3)ok1=1;
	if(s1[2]-'A'>=3&&s2[2]-'A'>=3)ok1=1;
	if(s2[2]=='F')s2[2]=='E';
	if(abs((s1[2]-'A')-(s2[2]-'A'))==1&&ok1)ok2=1;
	if(ct1==ct2)cout<<1;
	else cout<<0;
	if((ct1==ct2)&&(st1==st2))cout<<1;
	else cout<<0;
	if((ct1==ct2)&&(st1==st2)&&ok1)cout<<1;
	else cout<<0;
	if((ct1==ct2)&&(st1==st2)&&ok2)cout<<1;
	else cout<<0;
	return 0;
}
