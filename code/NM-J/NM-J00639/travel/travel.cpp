#include<bits/stdc++.h>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	char k1,k2;
	int c1,c2,s1,s2,a[4]={},x,y;
	cin>>c1>>s1>>k1>>c2>>s2>>k2;
	if(k1=='A'){
		x=1;
	}
	else if(k1=='B'){
		x=2;
	}
	else if(k1=='C'){
		x=3;
	}
	else if(k1=='D'){
		x=4;
	}
	else{
		x=5;
	}
	if(k2=='A'){
		y=1;
	}
	else if(k2=='B'){
		y=2;
	}
	else if(k2=='C'){
		y=3;
	}
	else if(k2=='D'){
		y=4;
	}
	else{
		y=5;
	}
	if(c1==c2){
		a[1]=1;
	}
	if(s1==s2&&a[1]==1){
		a[2]=1;
	}
	if(c1==c2&&s1==s2&&(x>=4&&y>=4 || x<=3&&y<=3)){
		a[3]=1;
	}
	if(abs(x-y)==1&&a[3]==1){
		a[4]=1;
	}
	cout<<a[1];
	cout<<a[2];
	cout<<a[3];
	cout<<a[4];
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
}
