#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin)
	freopen("travel.out","w",stdout)
	
	string s1[100],s2[100];
	int i,j,c1,c2;
	cin>>c1,s1,c2,s2;
		
		if(c1=c2){
			cout<<1;
			for(i=1;i<=3;i++){
				if(s1[1]==s2[1]&&s1[2]==s2[2]){
					cout<<1;
						if(s1[3]=="A"||s1[3]=="B"||s1[3]=="C"&&s2[3]=="A"||s2[3]=="B"||s2[3]=="C"||s1[3]=="D"&&s2[3]=="E"||s1[3]=="E"&&s2[3]=="D"){
						cout<<1;
							if(s1[3]=="A"&&s2[3]=="B"||s1[3]=="B"&&s2[3]=="A"||s2[3]=="C"||s1[3]=="C"&&s2[3]=="B"||s1[3]=="D"&&s2[3]=="E"||s1[3]=="E"&&s2[3]=="D"){
					cout<<1;
					
				}
					else cout<<0;
					}
				else{		
							cout<<00;
							break;
						}
					
					
					
					
					
					
					
				}
				else {
						cout<<000;
						break;
				}	
			
			
				
				
			}
			
			
		}
		else cout<<0000;
	
	
	
	
	
	
	
	
	fclose(stdin)
	fclose(stdout)
	return 0;
	
}
