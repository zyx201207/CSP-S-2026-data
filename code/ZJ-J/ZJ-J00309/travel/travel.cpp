#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char c1=s2[2],c2=s4[2];
	if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	char mn=min(c1,c2),mx=max(c1,c2);
	if((mn=='A'&&mx=='B')||(mn=='B'&&mx=='C')||(mn=='D'&&mx=='F'))cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
}