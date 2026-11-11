#include<bits/stdc++.h>
using namespace std;

main(){
    int c1,c2,a,b;
    char s1[100],s2[100];
    cin>>c1;
    for(int i=1;i<=3;i++){
    	cin>>s1[i];
	}
	
	cin>>c2;
	for(int i=1;i<=3;i++){
    	cin>>s2[i];
	}
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
        if(c1==c2){
            cout<<"1";
            if(s1[2]==s2[2]){
        	    cout<<"1";
        	    if(s1[3]=='D'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='D'){
			        cout<<"00";
		}
		    else{
			   cout<<"1";
			   if(s1[3]==s2[3]+1||s1[3]==s2[3]-1){
			      cout<<"1";
		   }
		       else{
      		      cout<<"0";
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