#include<bits/stdc++.h>
using namespace std;
long long sum=0,ans=0;
char s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			sum*=10;
			sum+=int(s1[i]-'0');
		}
		if(s1[i]>='A'&&s1[i]<='F'){
			s3=s1[i];
		}
	}
	for(int i=1;i<=s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			ans*=10;
			ans+=int(s2[i]-'0');
		}
		if(s2[i]>='A'&&s2[i]<='F'){
			s4=s2[i];
		}
	}
	if(c1==c2){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(sum==ans){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s3<='C'&&s4<='C'||s3>='D'&&s4>='D'){
		cout<<'1';
	}
	
	else{
		cout<<"00";
		return 0;
	}
	if(char(s3+1)==s4||char(s4+1)==s3){
		cout<<'1';
	}
	else{
		cout<<"0";
	}
	
	return 0;
} 
