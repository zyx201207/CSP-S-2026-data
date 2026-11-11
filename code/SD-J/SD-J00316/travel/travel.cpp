#include<bits/stdc++.h>
using namespace std;
long long n,m;
string sr,sx;char rr,rra,rrb,xx,xxa,xxb;//r/x数字，rr/xx字母 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	cin>>sr;
	cin>>m;
	cin>>sx;
	xxa=sx[0];
	xxb=sx[1];
	xx=sx[2];
	rra=sr[0];
	rrb=sr[1];
	rr=sr[2];
	if(n==m){//同一车厢 
		cout<<1;
		if(xxa==rra&&xxb==rrb){
			cout<<1;
			if((xx>='A'&&xx<='C'&&rr>='A'&&rr<='C')||(xx>='D'&&xx<='F'&&rr>='D'&&rr<='F')){
				cout<<1;
				if(xx+1==rr||rr+1==xx){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
				
			}
			else{
				cout<<"00";
			}
			
		}
		else{
			cout<<"000";
		}
	}	
	else{
		cout<<"0000"; 
	}
	return 0;
} 

