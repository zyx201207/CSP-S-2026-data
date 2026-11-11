#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<=1;i++){
			if(s1[i]!=s2[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<1;
		char r=s1[2],x=s2[2];
		if(((r=='A'||r=='B'||r=='C')&&(x=='A'||x=='B'||x=='C'))||((r=='E'||r=='F'))&&(x=='E'||x=='F'))
			cout<<1;
		else{
			cout<<"00";
			return 0;
		}
		if(r<x)  swap(r,x);
		if(r-x==1)  cout<<1;
		else  cout<<0;
	}
	else
		cout<<"0000";
	
	return 0;
}