#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+='1';
		bool flag=true;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				flag=false;
			}
		}
		if(flag){
			ans+='1';
			if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
				ans+='1';
				if(s1[2]>s2[2]){
					if((int)s1[2]-s2[2]==1){
						ans+='1';
					}
					else{
						ans+='0';
					}
				}
				else if(s2[2]>s1[2]){
					if((int)s2[2]-s1[2]==1){
						ans+='1';
					}
					else{
						ans+='0';
					}	
				}
			}
			else if((s1[2]>='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				ans+='1';
				ans+='1';
			}
			else{
				ans+='0';
				ans+='0';
			}
		}
		else{
			ans+='0';
			ans+='0';
			ans+='0';
		}		
	}
	else{
		ans+='0';
		ans+='0';
		ans+='0';
		ans+='0';
	}
	cout<<ans;
	return 0;
}
