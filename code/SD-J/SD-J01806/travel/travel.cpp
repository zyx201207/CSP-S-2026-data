#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<cstring>
#include<cmath>
#include<ostream>
#include<stdio.h>
using namespace std;
string a1[100],b1[100];
int e=0,f=0;
int bce1,dce1,bce2,dce2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	for(int i=0;i<b.size();i++){
		if(b[i]<='9' && b[i]>='0')
		{
			a1[e]=b[i]-'0';
			e++;
		}
	}
	for(int j=0;j<d.size();j++){
		if(d[j]<='9' && d[j]>='0')
		{
			b1[f]=d[j]-'0';
			f++;
		}
	}
		if(a==c && a1[1]==b1[1])
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	for(int i=2;i<b.size();i++){
		bool bce;
		if(b[i]=='A'||b[i]=='B'||b[i]=='C')
		{
			bce=true;
		}
		else
		{
			bce=false;
		}
		if(bce){
			bce1=1;
		}
		else{
			bce1=0;
		}
	}
	for(int j=2;j<b.size();j++){
		bool dce;
		if(d[j]=='A'||d[j]=='B'||d[j]=='C')
		{
			dce=true;
		}
		else
		{
			dce=false;
		}
		if(dce){
			dce1=1;
		}
		else{
			dce1=0;
		}
	}
	if(a==c && a1[1]==b1[1] && bce1==dce1)
{
	cout<<"1";
}
else{
	cout<<0;
}
for(int i=2;i<b.size();i++){
	if(b[i]=='A'){
		bce2=1;
	}
	if(b[i]=='B')
	{
		bce2=2;
	}
	if(b[i]=='C'){
		bce2=3;
	}
	if(b[i]=='D'){
		bce2=4;
	}
	if(b[i]=='F')
	{
		bce2=5;
	}
}
for(int j=2;j<b.size();j++){
	if(d[j]=='A'){
		dce2=0;
	}
	if(d[j]=='B')
	{
		dce2=1;
	}
	if(d[j]=='C'){
		dce2=2;
	}
	if(d[j]=='D'){
		dce2=3;
	}
	if(d[j]=='F')
	{
		dce2=4;
	}
}
if(a==c && a1[1]==b1[1] && bce1==dce1 &&bce2==dce2){
	cout<<"1";
}
else
{
	cout<<"0";
}
fclose(stdin);
fclose(stdout);
	return 0;
}
