#include<bits/stdc++.h>
using namespace std;
char ans1,ans2,ans3,ans4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	ans1='0',ans2='0',ans3='0',ans4='0';
	if(a1==b1) { 
		ans1='1';
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			ans2='1';	
			if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')){
				ans3='1';
				
				if((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='B'))
					ans4='1';
			}
			if((a2[2]=='D'||a2[2]=='F')&&(b2[2]=='D'||b2[2]=='F')){
				ans3='1';
				ans4='1';
			}
		} 
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
