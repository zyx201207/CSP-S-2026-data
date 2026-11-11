#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char x1,x2,x3,x4,x5,x6;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>x1>>x2>>x3>>c2>>x4>>x5>>x6;
	int n1=x1*10+x2,n2=x4*10+x5;
	bool b1,b2;
	if(x3>='D')b1=true;
	else b1=false;
	if(x6>='D')b2=true;
	else b2=false;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&n1==n2)cout<<1;
	else cout<<0;
	if(c1==c2&&n1==n2&&b1==b2)cout<<1;
	else cout<<0;
	if(c1==c2&&n1==n2&&b1==b2&&abs(x6-x3)==1)cout<<1;
	else cout<<0;
	return 0;
} 
