//wanghaoyu xidianzhongxue SN-J00636
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    if(c1[0]!=s1[0] && c1[1]!=s1[1]){
        s="0000";
    }else{
        s="1000";
        if(c2[0]==s2[0] && c2[1]==s2[1]){
            s="1100";
            if(c2[2]=='A'){
        		if(s2[2]=='B' || s2[2]=='C'){
                	s="1110";
                	if(s2[2]=='B')s="1111";
            	}else{
                	s="1100";
                	cout<<s;
            	}	
        	}
        	if(c2[2]=='B'){
            	if(s2[2]=='A' || s2[2]=='C'){
                	s="1111";
            	}else{
                	s="1100";
                	cout<<s;
            	}
        	}
        	if(c2[2]=='C'){
            	if(s2[2]=='A' || s2[2]=='B'){
                	s="1110";
                	if(s2[2]=='B')s="1110";
            	}else{
                	s="1100";
                	cout<<s;
            	}
        	}
        	if(c2[2]=='D'){
            	if(s2[2]=='E'){
                	s="1111";
            	}else{
                	s="1100";
                	cout<<s;
            	}
        	}
        	if(c2[2]=='E'){
            	if(s2[2]=='D'){
            	    s="1111";
            	}else{
                	s="1100";
                	cout<<s;
            	}
        	}
        }
    }
    cout<<s;
    return 0;
}
