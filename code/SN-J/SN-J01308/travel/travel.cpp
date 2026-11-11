#include<bits/stdc++.h>
using namespace std;
char ak[9]={'0','A','B','C'};
char bk[9]={'0','D','E'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a2,b,b2;
	int t,t2,k,k2;
	cin>>a>>a2>>b>>b2;
	if(a==b){
		cout<<1; 
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1; 
	}else{
		cout<<"000"; 
		return 0;
	}
	for(int i=1;i<=3;i++){
		if(a2[2]==ak[i]){
		    t=0;
			k=i;
		}
	}
	for(int i=1;i<=2;i++){
		if(a2[2]==bk[i]){
			t=1;
			k=i;
		}
	}
	for(int i=1;i<=3;i++){
		if(b2[2]==ak[i]){
		    t2=0;
			k2=i;
		}
	}
	for(int i=1;i<=2;i++){
		if(b2[2]==bk[i]){
			t2=1;
			k2=i;
		}
	}
	if(t==t2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((k+1)==k2||(k-1)==k2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0; 
}
