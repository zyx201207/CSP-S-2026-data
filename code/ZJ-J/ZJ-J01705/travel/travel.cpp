#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";	
	}else{
		cout<<"0000";
		return 0;
	}
	int len1=s1.size(),k1=0;
	int len2=s2.size(),k2=0;
	for(int i=0;i<len1-1;i++){
		k1=k1*10+(s1[i]-'0');
	}
	for(int i=0;i<len2-1;i++){
		k2=k2*10+(s2[i]-'0');
	}
	if(k1==k2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[len1-1]=='A'||s1[len1-1]=='B'||s1[len1-1]=='C')&&(s2[len2-1]=='D'||s2[len2-1]=='F')){
		cout<<"00";
		return 0;
	}
	if((s2[len2-1]=='A'||s2[len2-1]=='B'||s2[len2-1]=='C')&&(s1[len1-1]=='D'||s1[len1-1]=='F')){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if((s2[len2-1]=='D'&&s1[len1-1]=='F')||(s1[len1-1]=='D'&&s2[len2-1]=='F')){
		cout<<"1";
		return 0;
	}
	if((s2[len2-1]=='A'&&s1[len1-1]=='B')||(s1[len1-1]=='A'&&s2[len2-1]=='B')){
		cout<<"1";
		return 0;
	}
	if((s2[len2-1]=='B'&&s1[len1-1]=='C')||(s1[len1-1]=='B'&&s2[len2-1]=='C')){
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}
