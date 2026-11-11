#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q,w,e,r;
	int n=0,m=0;
	cin>>q>>w>>e>>r; 
	if(q==e&&q!="01"&&q!="16"){
		cout<<1;
		m=1;
	}else{
		cout<<0;
	}
	if(m==1){
		if(w[0]==r[0]&&w[1]==r[1]){
		cout<<1;
		n=1;
	}else{
		cout<<0;
	}		
	}else{
		cout<<0;
	}
	if(n==1){
		if(w[2]=='A'){
			if(r[2]=='B'){
				cout<<1<<1;
			    }else if(r[2]=='C'||r[2]=='D'||r[2]=='F'){
			    	cout<<1<<0;
				}
			}else if(w[2]=='B'){
				if(r[2]=='C'||r[2]=='A'){
					cout<<1<<1;
					}else if(r[2]=='D'||r[2]=='F'){
						cout<<1<<0;
					}
			}else if(w[2]=='D'){
				if(r[2]=='F'){
					cout<<1<<1;
				}else if(r[2]=='A'||r[2]=='B'||r[2]=='C'){
					cout<<1<<0;
				}
			}else if(w[2]=='F'){
				if(r[2]=='D'){
					cout<<1<<1;
				}else if(r[2]=='C'||r[2]=='A'||r[2]=='B'){
					cout<<1<<0;
				}
			}else if(w[2]=='C'){
				if(r[2]=='D'){
					cout<<0<<0;
				}else if(r[2]=='A'||r[2]=='B'){
					cout<<1<<0;
				}else if(r[2]=='F'){
					cout<<1<<0;
				}
			}else if(w[2]=='D'){
				if(r[2]=='C'){
					cout<<0<<0;
				}else if(r[2]=='F'){
					cout<<1<<0;
				}else if(r[2]=='A'||r[2]=='B'){
					cout<<0<<0;
				}
			}else if(w[2]==r[2]){
				cout<<0<<0;
			}else{
				cout<<0<<0;
			}	
	}else{
		cout<<0<<0;
	}
	
	return 0;
} 
