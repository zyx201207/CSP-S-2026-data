#include <bits/stdc++.h>
#include <cstdio>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string car1,seat1,car2,seat2;
	cin>>car1>>seat1>>car2>>seat2;
	long long a=0,b=0,c=0,d=0;
	if(car1==car2) a=1;
	if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]&&car1[0]==car2[0]&&car1[1]==car2[1]) b=1;
	if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]&&car1[1]==car2[1]){
		if(seat1[2]<='C'&&seat2[2]<='C'||seat1[2]>='D'&&seat2[2]>='D'){
			c=1;
			
		}
	
	}
	if(car1[0]==car2[0]&&car1[1]==car2[1]&&seat1[0]==seat2[0]&&seat1[1]==seat2[1]&&(seat1[2]<='C'&&seat2[2]<='C'||seat1[2]>='D'&&seat2[2]>='D') &&(seat1[2]+1==seat2[2]||seat1[2]-1==seat2[2])){
		d=1;
	}
	cout<<a<<b<<c<<d;
	
	return 0;
	
} 
