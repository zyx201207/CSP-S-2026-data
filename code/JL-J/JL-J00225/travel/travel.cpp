#include<bits/stdc++.h>
using namespace std;
string z1,z2,a1,a2;
char s1,s2,l1[3],l2[3];
int cnts=0,cntl=0;
int a[5]={0};
void check(string z1,string l1,char s1,string z2,string l2,char s2){
	if(z1!="01"&&z1!="16"&&z2!="01"&&z2!="16"&&z1==z2){
		a[1]=1;
	}else return;
	if(a[1]==1&&l1==l2)
	{a[2]=1;}
	else return;
	if(a[2]==1&&((s1>='A'&&s1<='C')&&(s2>='A'&&s2<='C'))||a[2]==1&&((s1=='D'&&s2=='F')||(s2=='D'&&s1=='F')))a[3]=1;
	else return;
	if((a[3]==1&&(s1>='A'&&s1<='C')&&abs(s2-s1)==1&&s2!='E')||a[3]==1&&((s1=='D'&&s2=='F')||(s2=='D'&&s1=='F')))a[4]=1;
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>z1>>a1>>z2>>a2;
	for(char c:a1){
		if(c>='0'&&c<='9'){
		l1[cntl]=c;
		cntl++;}
		if(c>='A'&&c<='F'){
			s1=c;
			cnts++;
		}
	}cnts=0;
	cntl=0;
	for(char d:a2){
		if(d>='0'&&d<='9'){
		l2[cntl]=d;
		cntl++;}
		if(d>='A'&&d<='F'){
			s2=d;
			cnts++;
		}
	}
	
	check(z1,l1,s1,z2,l2,s2);
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}return 0;
}

