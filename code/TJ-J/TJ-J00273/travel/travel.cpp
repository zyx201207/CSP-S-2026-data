#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool flag1=true;
bool flag2=false;
bool flag3=false;
bool flag4=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			flag1=false;
		}
	}
	if(flag1&&s1[1]==s2[1]&&s1[0]==s2[0]){
		flag2=true;
	}
	if(flag2&&flag1&&(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')){
		flag3=true;
		if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
			flag4==true; 
		}
	}
	else if(flag1&&flag2&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		flag3=true;
		if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
			flag4=true;
		}
	}
	cout<<int(flag1)<<int(flag2)<<int(flag3)<<int(flag4);
	fclose(stdin);
	fclose(stdout);
	
} 
