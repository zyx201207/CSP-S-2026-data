#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int k=1,q=1,s=1,h=1;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]) k=0;
	}
	cout<<k;
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]) q=0;
	}
	if(k==1&&q==1) cout<<1;
	else cout<<0;
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
		if(k==1&&q==1) s=1;
		else s=0;
	}
	else s=0;
	cout<<s;
	if(s==0) h=0;
	else{
		if(b[2]=='A'&&d[2]=='B') h=1;
		else if(b[2]=='B'&&d[2]=='A') h=1;
		else if(b[2]=='B'&&d[2]=='C') h=1;
		else if(b[2]=='C'&&d[2]=='B') h=1;
		else if(b[2]=='D'&&d[2]=='F') h=1;
		else if(b[2]=='F'&&d[2]=='D') h=1;
		else h=0;
	}
	cout<<h;
	return 0;
}