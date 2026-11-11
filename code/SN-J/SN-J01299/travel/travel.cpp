#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,c,k=0,kk=0;
	string b,d; 
	cin>>a>>b>>c>>d;
	if(a>=1&&a<17&&a==c){
		cout<<1;
		kk=1;
	}else{
		cout<<0;
		kk=0;
	}
	char x=min(b[2],d[2]),y=max(b[2],d[2]);
	if(b[0]+b[1]==d[0]+d[1]&&kk==1){
		cout<<1;
		k=1;
	}else{
		cout<<0;
	}
	if(b[2]=='A'&&d[2]<='C'||b[2]=='D'&&d[2]=='F'||d[2]=='A'&&b[2]<='C'||d[2]=='D'&&b[2]=='F'){
		if(k==1&&kk==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(y-x==1&&k==1){
		if(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C'&&kk==1){
			cout<<0;
		}else{
			cout<<1;
		} 
	}else{
		cout<<0;
	}
	return 0;
}
