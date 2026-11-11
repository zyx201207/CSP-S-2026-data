#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1;
	cin>>a>>b>>a1>>b1;
	int c,d;
	
	c=a.size();
	d=a1.size();
	
	if(c!=d){
	
		cout<<"0000";
	
}
	
		if(c==2){
			if(a[1]==a1[1]){
				cout<<"1";
				if(b[0]==b1[0] && b[1]==b1[1]){
					cout<<"1";
					if(b[2]>='A' && b[2]<='C'){
						
						if(b1[2]>='A' && b1[2]<='C'){
							cout<<"1";
							if(b[2]+1==b1[2] || b[2]-1==b1[2]){
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
						if(b1[2]>='D' && b1[2]<='F'){
							cout<<"11";
						}
						else{
							cout<<"00";
							
						}
					}
				}
				else{
					cout<<"000";
					
				}
			}
			else{
				cout<<"0000";
				
			}
		
		
	}
	else{
			if(a[2]==a1[2]){
				cout<<"1";
					if(b[0]==b1[0] && b[1]==b1[1]){
					cout<<"1";
					if(b[2]>='A' && b[2]<='C'){
						if(b1[2]>='A' && b1[2]<='C'){
							cout<<"1";
							if(b[2]+1==b1[2] || b[2]-1==b1[2]){
								cout<<"1";
							}
							else{
								cout<<"0";
							
							}
						}else{
							cout<<"00";
							
						}
					}
					else{
						if(b1[2]>='D' && b1[2]<='F'){
							cout<<"11";
						}
						else{
							cout<<"00";
						
						}
					}
				}
				else{
					cout<<"000";
			
				}
			}
			else{
				cout<<"0000";
	
			}
		}
	return 0;
}
