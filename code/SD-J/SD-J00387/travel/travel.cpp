#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)cout<<"1";
	else cout<<"0";
	
	if(c2[0]==c4[0]&&c2[1]==c4[1]&&c2!=c4&&c1==c3)cout<<"1";
	else cout<<"0";
	
	if(c2[0]==c4[0]&&c2[1]==c4[1]&&c2!=c4&&c1==c3){
		if(c2[2]=='D'||c2[2]=='F'){
			if(c4[2]=='D'||c4[2]=='F'){
				cout<<"1";
			}else cout<<"0";
		}else {
			if(c4[2]=='D'||c4[2]=='F'){
				cout<<"0";
			}else cout<<"1";
		}
	}else cout<<"0";
	
	int a,b;
	char s1=c2[2],s2=c4[2];
	a=c2[0]-'0'+c2[1]-'0',b=c4[0]-'0'+c4[1]-'0';
	if(a-1==b||a+1==b){
		if(c2[2]==c4[2]&&c1==c3){
			cout<<"1";
		}else cout<<"0";
	}
	else if(c1==c3&&(s2!='C'&&s1!='D')&&(s1!='C'&&s2!='D')&&(s1+1==int(s2)||s1-1==int(s2)))cout<<1;
	else cout<<"0";
	return 0;
}
