#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,nx,m,mx;
	char sn,sm;
	cin>>n>>nx>>sn>>m>>mx>>sm;
	if(n==m){
		if(nx==mx){
			if((sn=='A'&&(sm=='B'||sm=='C'))||(sn=='B'&&(sm=='A'||sm=='C'))||(sn=='C'&&(sm=='B'||sm=='A'))||(sn=='D'&&sm=='F')||(sn=='F'&&sm=='D')){
				if(abs(sn-sm)==1){
					cout<<1111;
				}
				else{
					cout<<1110;
				}
			}
			else{
				cout<<1100;
			}	
		}	
		else{
			cout<<1000;
		}
	}
	else{
		cout<<0000;
	}
} 
