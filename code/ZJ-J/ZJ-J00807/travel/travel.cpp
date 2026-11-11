#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,c2,s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		int flog1=0,flog2=0;
		if(s1[2]-'A'>2){
			flog1=1;
		}
		if(s2[2]-'A'>2){
			flog2=1;
		}
		if(s1[0]==s2[0]&&s1[1]==s2[1]&&flog1==flog2){
			cout<<1;
		}else{
			cout<<0;
		}
		int ss1=0,ss2=0;
		for(int i=0;i<2;i++){
			ss1+=s1[i]-'0';
			ss2+=s2[i]-'0';
			ss1*=10;
			ss2*=10;
		}
		int asd=0;
		if(ss1==ss2&&abs(s1[2]-s2[2])==1&&flog1==flog2){
			asd=1;
		}else if(s1[2]==s2[2]&&abs(ss1-ss2)==10){
			asd=1;
		}
		if(asd){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"0000";
	}	
	return 0;
}
