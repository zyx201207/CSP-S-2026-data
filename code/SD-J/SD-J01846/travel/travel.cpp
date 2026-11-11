#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,qw=0;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int e=(c[0]+'0')*10+(c[1]+'0'),f=(d[0]+'0')*10+(d[1]+'0');
	if(e==f)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F'))cout<<1,qw=1;
	else if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))cout<<1,qw=2;
	if(qw==0)cout<<0;
	if(qw==1)cout<<1;
	if(qw==2){
		if((c[2]=='A'||c[2]=='C')&&(d[2]=='A'||d[2]=='C'))cout<<0;
		else cout<<1;
	}
	if(qw==0)cout<<0;
	return 0;
}
