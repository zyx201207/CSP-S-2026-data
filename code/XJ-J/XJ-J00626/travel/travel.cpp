#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int  a,a2;
	char ch1,ch2;
	string c,s,c2,s2;
	string dui;
	dui="0000";
	cin>>c>>s;
	cin>>c2>>s2;
	if(c!=c2){
		cout<<dui;
		return 0;
	}
	dui[0]='1';
	int n1=s.size();
	int n2=s2.size();
	string x,x2;
	for(int i=0;i<n1;i++){
		if(s[i]>='A'&&s[i]<='F'){
			ch1=s[i];
			if(s[i]>='A'&&s[i]<='C'){
				a=1;
			}else{
				a=2;
			}
		}else{
			x+=s[i];
		}		
	}
	for(int i=0;i<n2;i++){
		if(s2[i]>='A'&&s2[i]<='F'){
			ch2=s2[i];
			if(s2[i]>='A'&&s2[i]<='C'){
				a2=1;
			}else{
				a2=2;
			}
		}else{
			x2+=s2[i];
		}		
	}
	if(x==x2){
		dui[1]='1';
	}
	if(a==a2){
		dui[2]='1';
	}
	int b;
	if(ch1>ch2){
		b=ch1-ch2;
	}else{
		b=ch2-ch1;
	}
	if(b==1){
		dui[3]='1';
	}
	cout<<dui;
	
	
	return 0;
}