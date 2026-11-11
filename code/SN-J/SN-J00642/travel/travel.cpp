//fengchenyao hanguangzhongxue SN-J00642
#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int s[4];
	cin>>s[1]>>s[3];
	if(s[1]<=17 && s[3]<=17){
	    if(s[1]!=1 && s[1]!=16 && s[3]!=1 && s[3]!=16){
	        if(s[1]==s[3]){
	    	    cout<<"1";
	        }
	        else{
		        cout<<"0";
	        }
	    }
	}
	cin>>s[2]>>s[4];
	cout<<s[2]."A";
	return 0;
}
