#include<bits/stdc++.h>
using namespace std;
int a;
char c,d,e;
int f;
char h,i,j;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>d>>e;
	cin>>f>>h>>i>>j;
	if(a==f){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if((c==h)&&(d==i)){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(e=='A'){
		if(j=='B'){
			cout<<1<<1;
			return 0;
		}
		else if(j=='C'){
			cout<<1<<0;
			return 0;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	if(e=='B'){
		if((j=='A')||(j=='C')){
			cout<<1<<1;
			return 0;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	if(e=='C'){
		if(j=='B'){
			cout<<1<<1;
			return 0;
		}
		else if(j=='A'){
			cout<<1<<0;
			return 0;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	if((e=='F'&&j=='D')||(e=='D'&&j=='F')){
		cout<<1<<1;
		return 0;
	}
	cout<<0<<0;
	return 0;
}
