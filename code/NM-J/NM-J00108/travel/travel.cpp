#include<bits/stdc++.h>
using namespace std;
int x1,x2;
string p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>p1>>x2>>p2;
	if(x1==x2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(p1[0]==p2[0]&&p1[1]==p2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(p1[2]=='F'&&p2[2]=='D'||p1[2]=='D'&&p2[2]=='F'||p1[2]=='A'&&p2[2]=='B'||p1[2]=='B'&&p2[2]=='A'){
		cout<<1;
	}
	else if(p1[2]=='B'&&p2[2]=='C'||p1[2]=='C'&&p2[2]=='B'||p1[2]=='A'&&p2[2]=='B'||p1[2]=='B'&&p2[2]=='A'||p1[2]=='A'&&p2[2]=='C'||p1[2]=='C'&&p2[2]=='A'){
		cout<<1;
	}
	else {
		cout<<0;
	}
	if(p1[2]=='F'&&p2[2]=='D'||p1[2]=='D'&&p2[2]=='F'||p1[2]=='A'&&p2[2]=='B'||p1[2]=='B'&&p2[2]=='A'){
		cout<<1;
	}
	else if(p1[2]=='B'&&p2[2]=='C'||p1[2]=='C'&&p2[2]=='B'||p1[2]=='A'&&p2[2]=='B'||p1[2]=='B'&&p2[2]=='A'){
		cout<<1;
	}
	else {
		cout<<0;
	}
	return 0;
}
