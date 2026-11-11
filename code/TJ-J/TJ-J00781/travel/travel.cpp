#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			cout<<1;
			if((s2[2]-'A'<3&&s4[2]-'A'<3)||(s2[2]-'A'>2&&s4[2]-'A'>2)){
		    	cout<<1;
		    	switch(s2[2]){
		    		case 'A':
		    			if(s4[2]=='B'){
		    				cout<<1;
		    				break;
						}
					case 'B':
		    			if(s4[2]=='A'||s4[2]=='C'){
		    				cout<<1;
		    				break;
						}
					case 'C':
		    			if(s4[2]=='B'){
		    				cout<<1;
		    				break;
						}
					case 'D':
		    			if(s4[2]=='F'){
		    				cout<<1;
		    				break;
						}
					case 'f':
		    			if(s4[2]=='D'){
		    				cout<<1;
		    				break;
						}
					default:
						cout<<"0";
						break;
				}
	    	}else{
	    		cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
	
}
