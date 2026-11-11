#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2,a,a2;
	int cnt=0,cnt2=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1=c2){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=0;i<=s1.size();i--){
		if(s1[i]>='0'||s1[i]<='9'){
			cnt=s1[i]-'0';
		}
		if(s1[i]>='A'||s1[i]<='Z'){
			a=s1[i];
		}
	}
	for(int i=0;i<=s2.size();i--){
		if(s2[i]>='0'||s2[i]<='9'){
			cnt2=s2[i]-'0';
		}
		if(s2[i]>='A'||s2[i]<='Z'){
			a2=s2[i];
		}
	}
	if(cnt==cnt2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a>='D'||a<='F'&&a2>='D'||a2<='F'){
		cout<<11;
		return 0;
	}else{
		cout<<00;
		return 0;
	}
	if(a>='A'||a<='C'&&a2>='A'||a2<='C'){
		cout<<1;
		if(a-a2==1||a2-a==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
