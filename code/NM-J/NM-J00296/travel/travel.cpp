#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a,b,lf=0;
	bool t=1;
	char c,d;
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	c=s1[2];
	d=s2[2];
	if(c1==c2)cout<<1;
	else {
		cout<<0;
		t=0;
	}
	if(a==b&&t){
		cout<<1;
	}
	else {
		cout<<0;
		t=0;
	}
	if(t&&(c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C')){
		cout<<1;
		lf=1;
	}
	else if(t&&(c=='D'||c=='F')&&(d=='D'||d=='F')){
		cout<<1;
		lf=2;
	}
	else {
		cout<<0;
		t=0;
	}
	if(t&&lf==1){
		if(abs(c-d)==1)cout<<1;
		else cout<<0;
	}
	else if(t&&lf==2){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
