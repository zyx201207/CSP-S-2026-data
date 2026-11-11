#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>s1>>s2>>s3>>s4;
	long long x=0,y=0,z=0,w=0;
	for(int i=0;i<s1.size();i++) x=x*10+(s1[i]-'0');
	for(int i=0;i<s2.size()-1;i++) y=y*10+(s2[i]-'0');
	for(int i=0;i<s3.size();i++) z=z*10+(s3[i]-'0');
	for(int i=0;i<s4.size()-1;i++) w=w*10+(s4[i]-'0');
	if(x==z){
		cout<<1;	
	}
	else{
		cout<<"0000";
		return 0;	
	}
	if(x==z&&y==w){
		cout<<1;	
	}
	else{
		cout<<"000";	
		return 0;
	}
	long long k=67-s2[s2.size()-1];
	long long g=67-s4[s4.size()-1];
	if((k>=0&&g>=0)||(k<0&&g<0)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if((s2[s2.size()-1]=='D'&&s4[s4.size()-1]=='F')||(s2[s2.size()-1]=='F'&&s4[s4.size()-1]=='D')){
		cout<<1;
	}
	else if(abs(k-g)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

