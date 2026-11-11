#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string l1,r1;
	char l2[100],r2[100];
	cin>>l1;
	for(int i=1;i<=3;i++){
		cin>>l2[i];
	}
	cin>>r1;
	for(int i=1;i<=3;i++){
		cin>>r2[i];
	}
	if(l1==r1){
		cout<<1;
		if(l2[1]==r2[1] and l2[2]==r2[2]){
			cout<<1;
			if((l2[3]=='A' or l2[3]=='B' or l2[3]=='C') and  (r2[3]=='A' or r2[3]=='B' or r2[3]=='C')){
				cout<<1; 
				if(l2[3]=='C' and r2[3]=='B'){
					cout<<1;
					return 0;
				}
				if(l2[3]=='B' and (r2[3]=='A' or r2[3]=='C')){
					cout<<1;
					return 0;
				}
				if(l2[3]=='A' and r2[3]=='B'){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
				}
			}
			if((l2[3]=='D' or l2[3]=='F') and  (r2[3]=='D' or r2[3]=='F')){
				cout<<1;
				if(l2[3]=='D' and r2[3]=='F'){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
				}
			}
			cout<<0<<0;
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
