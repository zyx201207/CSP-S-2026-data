#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	string  f[3];
	int e,t,s=0,w=0;
	bool q=false;
	cin>>a>>b>>c>>d;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		e=1;
	} else{
		e=0;
	}
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		t=1;
	} else{
		t=0;
	}
	if(b[2]=='A'){
		s=1;
	}
	if(b[2]=='B'){
		s=2;
	}
	if(b[2]=='C'){
		s=3;
	}
	if(b[2]=='D'){
		s=4;
	}
	if(b[2]=='F'){
		s=5;
	}
	if(d[2]=='A'){
		w=1;
	}
	if(d[2]=='B'){
		w=2;
	}
	if(d[2]=='C'){
		w=3;
	}
	if(d[2]=='D'){
		w=4;
	}
	if(d[2]=='F'){
		w=5;
	}
	if(a!=c){
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	} else{
		cout<<1;
		if(b[0]!=d[0]||b[1]!=d[1]){
			cout<<0;
			cout<<0;
			cout<<0;
		} else{
			cout<<1;
			if(e!=t){
					cout<<0;
					cout<<0;
			} else{
				cout<<1;
				if(s==1&&w==2){
					q=true;
				}
				if(s==2&&w==3){
					q=true;
				} 
				if(s==4&&w==5){
					q=true;
				} 
				if(q==true){
					cout<<1;
				} else cout<<0;
			}	
		}
	}
	return 0;
}
