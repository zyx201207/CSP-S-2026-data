#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
char s1,s2;
bool ans=1,f[1005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>s1>>a2>>b2>>s2;
	if(s1>s2){
		swap(s1,s2);
	}
	if((ans==1)&&(a1==a2)){
		cout<<1;	
	}else{
		ans=0;
		cout<<0;
	}
	if((ans==1)&&(b1==b2)){
		cout<<1;	
	}else{
		ans=0;
		cout<<0;
	}
	if((ans==1)&&(!(s1=='C'&&s2=='D'))){
		cout<<1;
	}else{
		ans=0;
		cout<<0;
	}
	if((ans==1)&&(!(s1=='A'&&s2=='C'))){
		cout<<1;
	}else{
		ans=0;
		cout<<0;
	}
	return 0;
}
