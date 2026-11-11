#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){//同一个车厢 
		
		
		cout<<"1";//同一个车厢 
		
		if(b[0]==d[0] and b[1]==d[1]){//同一列 
			
			cout<<"1";
			
			if(d[2]=='A' or d[2]=='B' or d[2]=='C'){//同一侧 
				if(b[2]=='A' or b[2]=='B' or b[2]=='C'){
				
					cout<<"1";
					//挨着 
					if(b[2]=='A' and d[2]=='B'){
						cout<<"1";
					}
					if(b[2]=='B' and d[2]=='A'){
						cout<<"1";
					}
					if(b[2]=='B' and d[2]=='C'){
						cout<<"1";
					}	
					if(b[2]=='C' and d[2]=='B'){
						cout<<"1";
					}
					
					if(b[2]=='A' and d[2]!='B'){
						cout<<"0";
					}
					if(b[2]=='B' and d[2]!='A'){
						cout<<"0";
					}
					if(b[2]=='B' and d[2]!='C'){
						cout<<"0";
					}
					if(b[2]=='C' and d[2]!='B'){
						cout<<"0";
					}
					
				}
				else{
					if(b[2]=='D' or b[2]=='F'){
						if(d[2]=='D' or d[2]=='F'){
							cout<<"1";
							if(b[2]=='D' and d[2]=='F'){
								cout<<"1";
							}		
							if(b[2]=='F' and d[2]=='D'){
								cout<<"1";
							}
							if(b[2]=='D' and d[2]!='F'){
								cout<<"0";
							}
							if(b[2]=='F' and d[2]!='D'){
								cout<<"0";
							}
						}
						
					}
					else{
						cout<<"00";
					
				}
			
		}
			}//ce
			else{
				cout<<"00";
			}
				
		}//lie
			
			
		else{
			cout<<"000";
		}
			
		
	
		  

	}//car 
	
	
	else{
		cout<<"0000";
	}//不同车厢 
	
	return 0;
}
