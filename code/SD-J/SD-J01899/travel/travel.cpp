#include<bits/stdc++.h>
using namespace std;
char c1[2],s1[3],c2[2],s2[3],ans[4];
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n;
	for(n=0;n<4;n++)ans[n]='0';
	for(n=0;n<2;n++)cin>>c1[n];
	for(n=0;n<3;n++)cin>>s1[n];
	for(n=0;n<2;n++)cin>>c2[n];
	for(n=0;n<3;n++)cin>>s2[n];
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			if(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C'){
				ans[2]='1';
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
				ans[3]='1';
			}
		}
	}
	
	for(n=0;n<4;n++)cout<<ans[n];
	return 0;
}
