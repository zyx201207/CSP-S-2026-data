#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	
	int n=0,m=0,x=0,y=0;
	cin>>a>>b>>c>>d;
	
	if(a==c){
		cout<<1;
		n=1;
	}else{
		cout<<0;
	}
	
	
	if(n==1 && b[0]==d[0] && b[1]==d[1]){
		cout<<1;
		m=1;
	}else{
		cout<<0;
	}
	
	
	if(n==1 && m==1 ){
		if((b[2]=='A'||b[2]=='B'||b[2]=='C') && (d[2]=='A'||d[2]=='B'||d[2]=='C')){
			x=1;
			cout<<1;
		}else{
			if((b[2]=='D'||b[2]=='F') && (d[2]=='D'||d[2]=='F')){
				x=1;
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	
	
	if(n==1 && m==1 && x==1 ){
		if(char(int(b[2])+1) == d[2] || char(int(b[2])-1) == d[2] ){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	return 0;
}
