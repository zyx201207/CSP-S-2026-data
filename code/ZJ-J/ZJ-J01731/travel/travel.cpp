#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
struct che{
	int xiang;
	int pai;
	char ABC;
}a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	IOS;
	cin>>a.xiang>>a.pai>>a.ABC;
	cin>>b.xiang>>b.pai>>b.ABC;
	if(a.xiang==b.xiang){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a.pai==b.pai){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((a.ABC>='D'&&b.ABC>='D')||(a.ABC<='C'&&b.ABC<='C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((a.ABC!='C'&&a.ABC!='D'&&abs(int(a.ABC)-int(b.ABC))==1)||(a.ABC=='C'&&b.ABC=='B')||(a.ABC=='D'&&b.ABC=='F')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
