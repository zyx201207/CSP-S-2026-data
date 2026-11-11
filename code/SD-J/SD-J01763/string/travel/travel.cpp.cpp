#include<bits/stdc++.h>
using namespace std;
string c,s,c2,s2,strs,strs2;
long long ans[10]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel,out","w",stdout);
    strs=s.size();
    strs2=s2.size();
    cin>>c>>s>>c2>>s2;
    if(c==c2){
    	ans[1]=1;
    	if(s[0]==s2[0]&&s[1]==s2[1]){
    		ans[2]=1;
    		if(s[2]!='D'&&s[2]!='F'&&s2[2]!='D'&&s2[2]!='F'){
			    ans[3]=1;
		    }else{
			    if(s[2]=='D'&&s2[2]=='F'||s[2]=='F'&&s2[2]=='D'){
				    ans[3]=1;
			    }else{
			        ans[3]=0;	
			    }
		    }
		}else{
			ans[2]=0;
			ans[3]=0;
		}
	}else{
		ans[1]=0;
		ans[2]=0;
		ans[3]=0;
	}
	if(ans[3]==1){
		if(s[2]=='A'){
			if(s2[2]=='B'){
				ans[4]==1;
			}else{
				ans[4]==0;
			}	   
		    cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
		    return 0;
	    }else if(s[2]=='B'){
	    	if(s2[2]=='C'||s2[2]=='A'){
	    		ans[4]=1;
			}else{
				ans[4]=0;
			}
		    cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
		    return 0;
		}else if(s[2]=='C'){
			if(s2[2]=='B'){
				ans[4]=1;
			}else{
				ans[4]=0;
			}
		    cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
		    return 0;
		}else if((s[2]=='D'&&s2[2]=='F')||(s[2]=='F'&&s2[2]=='D')){
	    	ans[4]=1;
	    	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	    	return 0;
		}else{
			ans[4]=0;
		}
	}else{
		ans[4]=0;
	}
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
//    cout<<ans[4];
	return 0;
} 
//Trick||Treat!    ||(s[2]=='B'&&s2[2]=='C'||s2[2]=='A')||s[2]=='C'&&s2[2]=='B'
