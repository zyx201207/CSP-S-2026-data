#include<bits/stdc++.h>
using namespace std;
int c1,c2,n=0,m=0;
char s1[5],s2[5],o,p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	n=s1[1]*10+s1[2];
	o=s1[3];
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	m=s2[1]*10+s2[2];
	p=s2[3];
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	if(c1==c2&&m==n){
		cout<<"1";
	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}
	if(n==m&&int(o)<=67&&int(o)>=65&&int(p)<=67&&int(p)>=65){
		cout<<"1";
		if(int(o)+1==p||int(o)-1==p){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		if(int(o)<=69&&int(o)>=68&&int(p)<=69&&int(p)>=68){
			cout<<"1";
			if(int(o)+1==p||int(o)-1==p){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
			cout<<"0";
		}
	}		 
	
	return 0;
}