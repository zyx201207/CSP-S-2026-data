#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int dy[1000];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	dy['A']=1;
	dy['B']=1;
	dy['C']=1;
	dy['D']=2;
	dy['F']=2;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s2[0]!=s4[0]||s2[1]!=s4[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(dy[s2[2]]!=dy[s4[2]]){
		cout<<"00";
		return 0;
	}cout<<1;
	if(dy[s2[2]]==2){
		cout<<1;
		return 0;
	}
	if(abs(s2[2]-s4[2])==1){
		cout<<1;
		return 0;
	}cout<<0;
	return 0;
}