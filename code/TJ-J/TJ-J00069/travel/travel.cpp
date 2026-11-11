#include <bits/stdc++.h>
using namespace std;
 int n,m,a,b,aa,bb,cc,dd;
 char p,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	cin>>m;
	cin>>p;
	cin>>a;
	cin>>b;
	cin>>l;
	for(int j=1;j<=17;j++){
		if(n==a&&n!=1&&n!=16&&a!=1&&a!=16){
		  aa==1;
		}else{
			aa==0;
		}
	}
	for(int i=1;i<=18;i++){
	   if(m==b&&n==a&&n!=1&&n!=16&&a!=1&&a!=16){
		bb==1;		
		}else {
			bb==0;
		}
	}
	for(int y=1;y<=5;y++){
		if(p=='A'&& l=='C'){
		cc==1;
		}
		else if(p=='A'&&l=='B'){
			cc==1;
		}
		else if(p=='B'&&l=='C'){
		   cc==1;
		}
		else if(p=='C'&& l=='A'){
			cc==1;
		}
		else if(p=='B'&&l=='A'){
			cc==1;
		}
		else if(p=='C'&&l=='B'){
			cc==1;
		}
		else if(p=='D'&&l=='F'){
		  cc==1;
		}
		else if(p=='F'&&l=='D'){
			cc==1;
		}else{
			cc==1;
		}
	}
	for(int i=1;i<=18;i++){
	   if(m==b){
			cc==1;	
		}else {
		    cc==0;
		} 
	}

	for(int u=1;u<=90;u++){
		if(m+1==b||m-1==b||m+18==b||m-18==b){
			dd==1;
		}else{
			dd==0;
		}
	}
	cout<<aa<<' '<<bb<<' '<<cc<<' '<<dd;
	return 0;
}
