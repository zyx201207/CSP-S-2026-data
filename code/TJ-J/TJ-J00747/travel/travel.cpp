#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,c2,s1,s2;
string ans="";
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2){
		ans+="1";
		int len=3;
	    if(s1[0]==s2[0]&&s1[1]==s2[1]){
	    	ans+="1";
	    	if(s1[2]<'D'&&s2[2]<'D'){
	    		ans+="1"; 
	    		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
	    			ans+="1";
				}
	    		else ans+="0";
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
