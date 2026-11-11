#include<bits/stdc++.h>
using namespace std;
int c1,c2,x,y,a1,a2;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>c2>>b;
	if(c1==c2){
		cout<<1;
		x+=(a[0]-'0')*10+a[1]-'0';
		y+=(b[0]-'0')*10+b[1]-'0';
		if(x==y)cout<<"1";
		else cout<<0;
		if('A'<=a[2]<='C'){
			a1=1;
		}
		if('A'<=b[2]<='C'){
			a2=1;
		}
		if(a1==a2)cout<<"1";
		else cout<<0;
		if(a[2]-b[2]==1||b[2]-a[2]==1)cout<<1;
		else cout<<0;
	}
	else {
		cout<<"0000";
	}
	return 0;
}