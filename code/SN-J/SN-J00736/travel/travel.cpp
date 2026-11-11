//冯睦子 SN-J00736 西安市渭北中学 
#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
string ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>ss1>>c2>>ss2;
	if(c1==c2)
		cout<<1;
	else
		cout<<0;
	p1=(ss1[0]-48)*10+ss1[1]-48;
	p2=(ss2[0]-48)*10+ss2[1]-48;
	if(p1==p2&&c1==c2)
		cout<<1;
	else
		cout<<0;
	if(p1==p2&&c1==c2){
		if((ss1[2]=='D'&&ss2[2]=='F')||(ss2[2]=='D'&&ss1[2]=='F'))
			cout<<1;
		else if(ss1[2]=='A'&&(ss2[2]=='B'||ss2[2]=='C'))
			cout<<1;
		else if(ss1[2]=='B'&&(ss2[2]=='A'||ss2[2]=='C'))
			cout<<1;
		else if(ss1[2]=='C'&&(ss2[2]=='B'||ss2[2]=='A'))
			cout<<1;
		else if(ss2[2]=='A'&&(ss1[2]=='B'||ss1[2]=='C'))
			cout<<1;
		else if(ss2[2]=='B'&&(ss1[2]=='A'||ss1[2]=='C'))
			cout<<1;
		else if(ss2[2]=='C'&&(ss1[2]=='B'||ss1[2]=='A'))
			cout<<1;
		else
			cout<<0;
	}else
		cout<<0;
	if(p1==p2&&c1==c2){
		if((ss1[2]=='D'&&ss2[2]=='F')||(ss2[2]=='D'&&ss1[2]=='F'))
			cout<<1;
		else if(ss1[2]=='A'&&ss2[2]=='B')
			cout<<1;
		else if(ss1[2]=='B'&&(ss2[2]=='A'||ss2[2]=='C'))
			cout<<1;
		else if(ss1[2]=='C'&&ss2[2]=='B')
			cout<<1;
		else if(ss2[2]=='A'&&ss1[2]=='B')
			cout<<1;
		else if(ss2[2]=='B'&&(ss1[2]=='A'||ss1[2]=='C'))
			cout<<1;
		else if(ss2[2]=='C'&&ss1[2]=='B')
			cout<<1;
		else
			cout<<0;
	}else
		cout<<0;
	return 0;
}
