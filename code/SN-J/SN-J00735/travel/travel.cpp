#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string a,c;
	int t,r,m,n,x,y,z,ch,b;
	cin>>t;
	cin>>a;
	cin>>r;
	cin>>c;
	if(t!=r){
		cout<<"0000";
		return 0;
	}
	x=a[0]-48;
	y=a[1]-48;
	m=x*10+y;
	x=c[0]-48;
	y=c[1]-48;
	n=x*10+y;
	if(n!=m){
		cout<<"1000";
		return 0;
	}
	x=a[2]-65;
	y=c[2]-65;
	if(x>y){
		ch=x-y;
		b=x;
	}
	else{
		ch=y-x;
		b=y;
	}
	if(b==3){
		cout<<"1100";
		return 0;
	}
	if(ch==5&&ch!=2){
		cout<<"1100";
		return 0;
	}
	if(b!=3&&ch==1){
		cout<<"1111";
		return 0;
	}
	else if(b==5&&ch==2){
		cout<<"1111";
		return 0;
	}
	else{
		cout<<"1110";
		return 0;
	}
	return 0;
}
