#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool check(char x,char y,int k){
	if(k==1){
	if((x=='A'&&y=='B')||(x=='A'&&y=='C')||(x=='B'&&y=='C')||(x=='D'&&y=='F'))
	return 1;
	else
	return 0;
 if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='D'&&y=='F'))
	return 1;
	else 
	return 0;	
	}} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		string e=b.substr(0,2),f=d.substr(0,2);
		if(e==f){
			cout<<'1';
		if(check(d.[d.size()-1]),1||(check(b.[b.size()-1],1))||(check(b.[b.size()-1],1))||(check(d.[d.size()-1],1)))
			cout<<'1';	
			else cout<<'0';
		}
	if(check(d.[d.size()-1]),0)||(check(b.[b.size()-1],0)||(check(b.[b.size()-1],0)||(check(d.[d.size()-1],0)cout<<"1";
		else cout<<"00";
	}else{
		cout<<"000";
	}else{
			cout<<"0000";
		}
} 
