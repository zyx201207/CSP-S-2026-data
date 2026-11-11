#include<bits/stdc++.h>
using namespace std;
int x,y,x2,y2;
string c1,s1,c2,s2;
int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else x=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]) y=1;
	int uu=s1[2]-'A';
	int rr=s2[2]-'A';
	if(y!=0) {
		
		if((uu==3||uu==4)&&(rr==3||rr==4)){
			x2=1;
		}
		else if((uu==0||uu==1||uu==2)&&(rr==0||rr==1||rr==2)){
			x2=1;
		}
	}
	if(x2!=0){
		if(abs(uu-rr)==1) y2=1;
	}
	cout<<x<<y<<x2<<y2;

	return 0;
} 
