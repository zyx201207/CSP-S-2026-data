#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,cu;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
    	cu+="1";
    	if  (s1[0]==s2[0]&&s1[1]==s2[1]){
    		cu+="1";
    		if (((s1[2]=='A'
	    	    	||s1[2]=='B'
	    	    	||s1[2]=='C')
	    		&&(s2[2]=='A'
			    	||s2[2]=='B'
			    	||s2[2]=='C'))
		    	||((s1[2]=='D'
		    		||s1[2]=='F')
    		    &&(s2[2]=='D'
					||s2[2]=='F'))){
    			cout<<'1';
				if ((s1[2]=='A'&&s2[2]=='B')
					||(s1[2]=='B'&&s2[2]=='C')
					||(s1[2]=='D'&&s2[2]=='F')
					||(s1[2]=='B'&&s2[2]=='A')
					||(s1[2]=='C'&&s2[2]=='B')
					||(s1[2]=='F'&&s2[2]=='D')){
					cu+="1";
				}else{
					cu+="0";
				}
     		}else{
    			cu+="00";
    		}
	    }else{
			cu+="000";
		}
	}else{
		cu+="0000";
	}
	cout<<cu<<endl;
	return 0;
}
