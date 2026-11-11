#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1;
	string s2;
	string c1;
	string c2;
	freopen("travel","r",stdin);
	freopen("travel","w",stdout); 
	int flag4=0;
	int flag1=0;
	int flag2=0;
	int flag3=0;
	cin>>c1>>s1>>c2>>s2;
		if(c1==c2)flag1=1;
		else {
		cout<<"0000";
		return 0;
	}
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		flag2=1;
		}
		else {
			cout<<flag1<<flag2<<"00";
			return 0;
		}
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s1[2]=='B'||s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
			flag3=1; 
		}
		else {
			cout<<flag1<<flag2<<flag3<<"0";
			return 0; 
		}
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]||s2[2]+1==s1[2]||s2[2]-1==s1[2]) {
			flag4=1;
		}
		cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
