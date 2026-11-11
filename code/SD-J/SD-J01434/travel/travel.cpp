#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if((s2[0]!=s4[0])||(s2[1]!=s4[1])){
		cout<<"000";
		return 0;
	}
	cout<<1;
	int is_1=0,is_2=0;
	if(s2[2]-'A'<3){
		is_1=1;
	}
	if(s4[2]-'A'<3){
		is_2=1;
	}
	if(is_1!=is_2){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if((abs(s2[2]-s4[2])==1)){
		if((s2[2]=='D' && s4[2]=='C')|| (s2[2]=='C' &&s4[2]=='D')){
			cout<<"0";
		}
		else{
			cout<<1;
		}
		return 0;
	}
	if((s2[2]=='D' && s4[2]=='F')|| (s2[2]=='F' &&s4[2]=='D')){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
