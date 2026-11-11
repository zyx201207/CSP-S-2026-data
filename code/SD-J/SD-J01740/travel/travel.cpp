#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,r,b,x;
	cin>>a>>r>>b>>x;
	if(a==b)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(r[0]==x[0]&&r[1]==x[1])
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((r[2]>='A'&&r[2]<='C'&&x[2]>='A'&&x[2]<='C')||(r[2]>='D'&&r[2]<='F'&&x[2]>='D'&&x[2]<='F'))
		cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if((r[2]>='A'&&r[2]<='C'&&x[2]>='A'&&x[2]<='C'&&(r[2]+1==x[2]||r[2]-1==x[2]))||(r[2]>='D'&&r[2]<='F'&&x[2]>='D'&&x[2]<='F'))
		cout<<1;
	else cout<<0;
	return 0;
}
