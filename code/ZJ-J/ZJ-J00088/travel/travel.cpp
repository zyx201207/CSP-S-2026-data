#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ic1,ic2,is1,is2;
char es1,es2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	es1=s1[s1.size()-1],es2=s2[s2.size()-1];
	for(int i=0;i<c1.size();i++) ic1=ic1*10+(c1[i]-'0');
	for(int i=0;i<s1.size()-1;i++) is1=is1*10+(s1[i]-'0');
	for(int i=0;i<c2.size();i++) ic2=ic2*10+(c2[i]-'0');
	for(int i=0;i<s2.size()-1;i++) is2=is2*10+(s2[i]-'0');
	if(ic1==ic2){
		cout<<1;
		if(is1==is2){
			cout<<1;
			if(((es1=='A'||es1=='B'||es1=='C')&&(es2=='A'||es2=='B'||es2=='C'))||((es1=='D'||es1=='F')&&(es2=='D'||es2=='F'))){
				cout<<1;
				if((es1=='A'&&es2=='B')||(es1=='B'&&(es2=='A'||es2=='C'))||(es1=='C'&&es2=='B')) cout<<1;
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}