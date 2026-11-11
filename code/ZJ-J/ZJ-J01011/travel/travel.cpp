#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){ 
	    cout<<1<<" ";
	    if(s1==s2){
	        cout<<1<<" "<<1<<" "<<1;
	    } 
        else{
        	if(s1[0]==s2[0]){
        		if(s1[1]==s2[1]){
        			cout<<1<<' ';
        			
        			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[3]=='F'&&s2[3]=='D')) cout<<1<<" "<<1;
        			else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')||(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))cout<<1<<" "<<0;
        			else cout<<0<<" "<<0;
				}
        		else{
				    cout<<0<<' '<<0<<' '<<0;	
				}
				
			}
		   else if(s1[1]!=s2[1]) cout<<0<<' '<<0<<" "<<0;
		}
	      
	}
	else if(c1!=c2) cout<<0<<" "<<0<<" "<<0<<" "<<0;
	return 0;
}