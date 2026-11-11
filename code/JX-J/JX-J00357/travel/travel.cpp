#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
char z1[2],z2[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(r2[0]+r2[1]==x2[0]+x2[1]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((r2[2]>='A' and r2[2]<='C' and x2[2]>='A' and x2[2]<='C') or (r2[2]>='D' and r2[2]<='F' and x2[2]>='D' and x2[2]<='F')) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(abs(r2[2]-x2[2])==1) cout<<1;
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
