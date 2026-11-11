#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,x1;
	string r2,x2;
	char r,x;
	cin>>r1>>r2>>r;
	cin>>x1>>x2>>x;
	if(r1==x1)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}if(r2[0]==x2[0]&&r2[1]==x2[1])cout<<1;
	else {
		cout<<0<<0<<0;
		return 0;
	}
	if((r2[2]<'D'&&x2[2]<'D')||(r2[2]>='D'&&x2[2]>='D'))cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(r2[2]+1==x2[2]||r2[2]-1==x2[2])cout<<1;
	else cout<<0;
	return 0;
}
