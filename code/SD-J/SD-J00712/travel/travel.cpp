#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[5],c2[5],s1[5],s2[5];
	int a=0;
	cin>>c1>>c2>>s1>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]==s1[i]){
			a++;
		}
	}
	if(a==2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	a=0;
	for(int i=0;i<2;i++){
		if(c2[i]==s2[i]){
			a++;
		}
	}
	if(a==2){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((c2[2]>=65&&c2[2]<=67&&s2[2]>=65&&s2[2]<=67)||(c2[2]>=68&&c2[2]<=70&&s2[2]>=68&&s2[2]<=70)){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs(s2[2]-c2[2])==1&&c2[2]<=67&&s2[2]<=67){
		cout<<1;
	}else{
		if(c2[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&c2[2]=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
