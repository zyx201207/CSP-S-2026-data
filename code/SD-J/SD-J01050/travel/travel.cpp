#include<bits/stdc++.h>
using namespace std;
string car1,car2,seat1,seat2;
int a,b,c,d;
char aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>car1>>seat1>>car2>>seat2;
	a=car1[0]-'0';
	a*=10;
	a+=(car1[1]-'0');
	c=car2[0]-'0';
	c*=10;
	c+=(car2[1]-'0');
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	aa=seat1[2],bb=seat2[2];
	b=seat1[0]-'0';
	b*=10;
	b+=(seat1[1]-'0'); 
	
	d=seat2[0]-'0';
	d*=10;
	d+=(seat2[1]-'0');
	if(b!=d){
		cout<<"1000";
		return 0;
	}
//	cout<<aa<<" "<<bb;
	if(aa=='A'&&bb=='B'||aa=='A'&&bb=='C'||aa=='B'&&bb=='A'||aa=='B'&&bb=='C'||aa=='C'&&bb=='A'||aa=='C'&&bb=='B'||aa=='D'&&bb=='F'||aa=='F'&&bb=='D'){
		if(aa=='F'||aa=='D'||aa=='A'&&bb=='B'||aa=='B'&&bb=='A'||aa=='B'&&bb=='C'||aa=='C'&&bb=='B'){
			cout<<"1111";
		}
		else{
			cout<<"1110";
		}
	}
	else cout<<"1100";
	return 0;
}
