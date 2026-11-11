#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2){
		ans+="1";//1
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+="1";//2
			if((s1[2]>='D'&&s2[2]<='C')||(s1[2]<='C'&&s2[2]>='D')){
				ans+="00";//3
				cout<<ans;
			}
			else{
				ans+="1";//3
				if(abs(s1[2]-s2[2])==1){
					ans+="1";//4
					cout<<ans;
				}
		    	else {
					ans+="0";//4
					cout<<ans;
				}
			}
		}
		else {
			ans+="000";//2
			cout<<ans;
		}
	}
	else {
		ans="0000";//1
		cout<<ans;
	}
	
	return 0;
}
