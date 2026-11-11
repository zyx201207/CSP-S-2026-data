#include<bits/stdc++.h>
using namespace std;
struct name{
	string che;
	string wei;
};

int main(){
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdin);
	name r,x;
	cin>>r.che>>r.wei>>x.che>>x.wei;
	char g,h,j,k;
	g=r.wei[0];
	h=r.wei[1];
	j=x.wei[0];
	k=x.wei[1];
	if(r.che==x.che){
		cout<<1;
		if(g==j&&h==k){
		
		
			cout<<1;
			if(r.wei[3]=='A'||r.wei[3]=='B'||r.wei[3]=='C'){
			
				if(x.wei[3]=='A'||x.wei[3]=='B'=='C'){
				
					cout<<1;
					if(r.wei[3]=='A'||r.wei[3]=='B'){
						cout<<1;						
					}
					else if(r.wei[3]=='B'){
						cout<<1;
					}
					else if(r.wei[3]=='C'&&x.wei[3]=='B'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
			}
			else if(r.wei[3]=='D'||r.wei[3]=='F'){
			
				if(x.wei[3]=='D'||x.wei[3]=='F'){
				
					cout<<1;
					cout<<1;
				}
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
	
	
	
	
