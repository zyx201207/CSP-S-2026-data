#include<bits/stdc++.h>
using namespace std;

string c1,c2,c3,c4;
int a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		a=a*10+(c2[i]-'0');
		b=b*10+(c4[i]-'0');
	}
	c=c2[2];
	d=c4[2];
	if(a==b) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(((c>='A'&&c<='C')&&(d>='A'&&d<='C'))||((c>='D'&&c<='F')&&(d>='D'&&d<='F'))) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(c+1==d||c-1==d) cout<<1;
	else{
		cout<<"0";
		return 0;
	}
	
	return 0;
}
