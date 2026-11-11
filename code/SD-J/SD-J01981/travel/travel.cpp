#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	int f=1;
	for(int i=0;i<2;i++)
		if(ca[i]!=cb[i]) f=0;
	if(f==0){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	int fa=1;
	for(int i=0;i<2;i++)
		if(sa[i]!=sb[i]) fa=0;
	if(fa==0){
		cout<<"000";
		return 0;
	}else{
		cout<<1;
	}
	int fb=0;
	if((sa[2]<='C'&&sb[2]<='C')||(sa[2]>'C'&&sb[2]>'C')) fb=1;
	if(fb==1){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	int x,y;
	x=int(sa[2]);
	y=int(sb[2]);
	if(abs(x-y)==1) cout<<1;
	else cout<<0;	
	return 0;
} 
