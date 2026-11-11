#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0; 
	}
	else cout<<"1";
	r=(s1[0]-'0')*10+(s1[1]-'0');
	x=(s2[0]-'0')*10+(s2[1]-'0');
	if(r==x) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D') cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
