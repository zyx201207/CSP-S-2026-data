#include <iostream>
#include <stdio.h>
#include <cstring>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool qa,qb,qc,qd;
short l,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		if(c1[i]!=c2[i]) qa=true;
	}
	if(qa==true){
		cout<<"0000";
		return 0;
	} 
	else cout<<1;
	
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]) qb=true;
	}
	if(qb==true){
		cout<<"000";
		return 0;	
	}
	else cout<<1;
		
	if(s1[2]=='D'||s1[2]=='F') l++;
	else r++;
	if(s2[2]=='D'||s2[2]=='F') l++;
	else r++;
	if(l==r){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	
	if((s2[2]-1==s1[2]||s1[2]-1==s2[2])&&l!=r) cout<<1;
	else cout<<0;
	
	return 0;
} 
