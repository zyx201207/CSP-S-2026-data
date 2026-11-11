#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	string x="",y="";
	x+=s1[0];
	x+=s1[1];
	y+=s2[0];
	y+=s2[1];
	if(x==y&&c1==c2)cout<<1;
	else cout<<0;
	char r=s1[2],c=s2[2];
	if(r>='A'&&r<='C'&&c>='A'&&c<='C'&&x==y&&c1==c2)cout<<1;
	else if(r>='D'&&r<='F'&&c>='D'&&c<='F'&&x==y&&c1==c2)cout<<1;
	else cout<<0;
	if(x==y&&c1==c2&&r>='A'&&r<='C'&&c>='A'&&c<='C'){
		if(abs(r-c)==1)cout<<1;
		else cout<<0;
	}else if(x==y&&c1==c2&&r>='D'&&r<='F'&&c>='D'&&c<='F'){
		if(abs(r-c)==1)cout<<1;
		else cout<<0;
	}else cout<<0;
	return 0;
}
