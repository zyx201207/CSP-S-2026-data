#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F'){
		cout<<"11";
		return 0;
	}else if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(s2[2]-s4[2])==1){
		cout<<"1";
		return 0;
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
