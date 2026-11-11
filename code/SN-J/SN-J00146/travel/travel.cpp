#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string x1,y1,x2,y2;
	bool b=true,v=true;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(x1==x2&&y1[0]==y2[0]&&y1[1]==y2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(x1==x2&&y1[0]==y2[0]&&y1[1]==y2[1]){
		if(y1[2]>='A'&&y1[1]<='C'&&y2[2]>='A'&&y2[2]<='C'){
			cout<<1;
			b=false;
		}
		if(y1[2]>='D'&&y1[2]<='F'&&y2[2]>='D'&&y2[2]<='F'){
			cout<<1;
			b=false;
		}
	}
	if(b==true){
		cout<<0;
	}
	if(b==false){
		if(y1[2]=='A'&&y2[2]=='B'||y2[2]=='A'&&y1[2]=='B'){
			cout<<1;
			v=false;
		}
		if(y1[2]=='B'&&y2[2]=='C'||y1[2]=='B'&&y2[2]=='C'){
			cout<<1;
			v=false;
		}
		if(y1[2]=='D'&&y2[2]=='F'||y1[2]=='D'&&y2[2]=='F'){
			cout<<1;
			v=false;
		}
	}
	if(v==true){
		cout<<0;
	}
	
	return 0; 
}
