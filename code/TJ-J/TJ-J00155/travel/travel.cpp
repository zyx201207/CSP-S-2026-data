#include<bits/stdc++.h>
using namespace std;
char c1[50],c2[50],s1[50],s2[50];
char ans[50];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++) cin>>c1[i];
	for(int i=0;i<3;i++) cin>>s1[i];
	for(int i=0;i<2;i++) cin>>c2[i];
	for(int i=0;i<3;i++) cin>>s2[i];
	//处理 
	if(s1[2]=='A'){
		s1[2]='1';
	}else if(s1[2]=='B'){
		s1[2]='2';
	}else if(s1[2]=='C'){
		s1[2]='3';
	}else if(s1[2]=='D'){
		s1[2]='5';
	}else if(s1[2]=='F'){
		s1[2]=='6';
	}
	if(s2[2]=='A'){
		s2[2]='1';
	}else if(s2[2]=='B'){
		s2[2]='2';
	}else if(s2[2]=='C'){
		s2[2]='3';
	}else if(s2[2]=='D'){
		s2[2]='5';
	}else if(s2[2]=='F'){
		s2[2]=='6';
	}
	//问题 
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		cout<<"0000";
	}else if(c1[0]==c2[0]&&c1[1]==c2[1]){
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			if((s1[2]>='1'&&s1[2]<='3'&&s2[2]>='1'&&s2[2]<='3')||(s1[2]>='5'&&s1[2]<='6'&&s2[2]>='5'&&s2[2]<='6')){
				ans[2]='1';
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					ans[3]='1';
					cout<<ans;
				}else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}
	return 0;
}
