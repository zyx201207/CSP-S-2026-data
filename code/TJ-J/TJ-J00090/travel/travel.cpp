#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2,pai_a="",pai_b="";
	cin>>a1>>a2>>b1>>b2;
	char zuo_a=a2[2];
	char zuo_b=b2[2];
	if(a1==b1){
		cout<<1;
		pai_a=a2[0]+a2[1];
		pai_b=b2[0]+b2[1];
		if(pai_a==pai_b){
			cout<<1;
			if(zuo_a>='A' && zuo_a<='C' && zuo_b>='A' && zuo_b<='C'){
				cout<<1;
			}else if(zuo_a=='D' && zuo_b=='F' || zuo_b=='D' && zuo_a=='F'){
				cout<<1;
			}else
				cout<<0;
			if((zuo_a+1==zuo_b || zuo_a-1==zuo_b) && (zuo_a!='C' && zuo_b!='D'))
				cout<<1;
			else
				cout<<0;
		}else
			cout<<"000";
	}else
		cout<<"0000";
	
	return 0;
} 
