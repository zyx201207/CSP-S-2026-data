#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s2[1]==s4[1]&&s4[0]==s2[0]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	int b1=1;
	if((s2[2]=='A'||s2[2]=='B')||s2[2]=='C'){
		if((s4[2]=='A'||s4[2]=='B')||s4[2]=='C'){
			cout<<1;
			b1=0;
			if(s2[2]=='B'||s4[2]=='B')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	if(s2[2]=='D'||s2[2]=='E'){
		if(s4[2]=='D'||s4[2]=='E'){
			cout<<"11";
			b1=0;
		}
	}
	if(b1)
	{
		cout<<"00";
	}
	return 0;
}
