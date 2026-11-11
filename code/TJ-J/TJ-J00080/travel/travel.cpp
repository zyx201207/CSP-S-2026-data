#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0,c=0,d=0;
	//对于a:
	if(c1==c2){
		a=1;
		
	}
	else{
		cout<<"0000";
		return 0;
	} 
	//对于b：
	 char n0=s1[0],n1=s1[1];
	 char m0=s2[0],m1=s2[1];
	 if(n0==m0&&n1==m1){
	 	b=1;
	 }
	 else{
	 	cout<<"1000";
	 	return 0;
	 }
	 //对于c:
	 char seat1=s1[2],seat2=s2[2];
	 if(seat1=='A'){
	 	if(seat2=='B'){
	 		c=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
	 }
	 else if(seat1=='B'){
	 	if(seat2=='A'||seat2=='C'){
	 		c=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
	 } 
	 else if(seat1=='C'){
	 	if(seat2=='A'||seat2=='B'){
	 		c=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
	 }
	 //对于d:
	 if(seat1=='A'&&seat2=='B'){
	 	d=1;
	 } 
	 else if(seat1=='B'&&seat2=='A'){
	 	d=1;
	 }
	 else if(seat1=='B'&&seat2=='C'){
	 	d=1;
	 }
	 else if(seat1=='C'&&seat2=='B'){
	 	d=1;
	 }
	 else if(seat1=='D'&&seat2=='F'){
	 	d=1;
	 }
	 else if(seat1=='F'&&seat2=='D'){
	 	d=1;
	 }
	 cout<<a<<b<<c<<d;
	return 0;
} 
