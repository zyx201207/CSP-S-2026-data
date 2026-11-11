#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1,s2;
	int a1,a2;
	cin>>c1>>a1>>s1>>c2>>a2>>s2;
	int a=1,b=1,c=1,d=1;
	if(c1!=c2){
		a=0;
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a1!=a2){
		b=0;
		cout<<1<<0<<0<<0;
		return 0;
	}
	if((s1=='C'&&s2=='D')||(s1=='D'&&s2=='C')){
		c=0;
		cout<<1<<1<<0<<0;
		return 0;
	}
	if(s1-s2!=1&&s2-s1!=1){
		d=0;
		cout<<1<<1<<1<<0;
		return 0;
	}
	cout<<1<<1<<1<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
