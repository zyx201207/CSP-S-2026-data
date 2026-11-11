#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a,c;
	int p,q;
	char e,f;
	cin>>a>>p>>e>>c>>q>>f;
	int n=0,m=0,x=0,y=0;
	if(a!=c){
		cout<<n<<m<<x<<y;
	}else{
		n=1;
		if(p==q){
			m=1;
			if((e=='A'||e=='B'||e=='C')&&(f=='A'||f=='B'||f=='C')){
				x=1;
			if((e=='A'&&f=='B')||(e=='B'&&f=='A')||(e=='B'&&f=='C')||(e=='C'&&f=='B')){
				y=1;
			}
		}
			if((e=='D'||e=='F')&&(f=='D'||f=='F')){
				x=1;
			if((e=='D'&&f=='F')||(e=='F'&&f=='D')){
				y=1;
				}
			}
		}
		cout<<n<<m<<x<<y;
	}
	return 0;
} 
