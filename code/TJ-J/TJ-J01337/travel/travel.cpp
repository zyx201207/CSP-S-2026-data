#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int r,t,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			r=int(b[2])-int('A')+1;
			t=int(d[2])-int('A')+1;
			if(r==1&&t==2) e=1;
			if(r==2&&t==1) e=1;
			if(r==3&&t==2) e=1;
			if(r==2&&t==3) e=1;
			if(r==3&&t==1) e=1;
			if(r==1&&t==3) e=1;
			if(r==4&&t==5) e=1;
			if(r==5&&t==4) e=1;
			if(e==1){
				cout<<1;
				e=0;
				if(r==4&&t==5) e=1;
				if(r==5&&t==4) e=1;
				if(r==1&&t==2) e=1;
				if(r==2&&t==1) e=1;
				if(r==3&&t==2) e=1;
				if(r==2&&t==3) e=1;
				if(e==1) cout<<1;
				else cout<<0;
			}
			else{
				cout<<0;
				cout<<0;
			}
		} 
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
} 
//02 01A 02 01B
