#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,cx1,cx2,zw1,zw2;
	cin>>c1>>s1>>c2>>s2;
	cx1[0] = s1[0];
	cx1[1] = s1[1];
	zw1 = s1[2];
	cx2[0] = s2[0];
	cx2[1] = s2[1];
	zw2 = s2[2];
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&cx1==cx2){
		cout<<1;
	}else{
		cout<<0;
	}
	int flag = 0;
	if(c1==c2&&cx1==cx2){
		if(zw1=="A"||zw1=="B"||zw1=="C"){
			if(zw2=="A"||zw2=="B"||zw2=="C"){
				cout<<1;
				flag = 1;
			}
		}
		if(zw1=="D"||zw1=="E"){
			if(zw2=="D"||zw2=="E"){
				cout<<1;
				flag = 1;
			}
		}
	}
	if(flag==0){
		cout<<0;
	}
	if(c1==c2&&cx1==cx2&&flag==1){
		char a,b;
		a = zw1[0];
		b = zw2[0];
		if(a+1==b){
			cout<<1;
		}else if(a-1==b){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
