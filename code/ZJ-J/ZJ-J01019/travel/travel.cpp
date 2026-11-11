#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			int s=0,t=0;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C')s=1;
			if(d[2]=='A'||d[2]=='B'||d[2]=='C')t=1;
			if(s==t)cout<<1;
			else cout<<0;
		}else cout<<"00";
		int x=(b[0]-'0')*10+b[1]-'0',y=(d[0]-'0')*10+d[1]-'0';
		if((x-y==1||x-y==-1)&&b[2]==d[2])cout<<1;
		else if(x==y&&(b[2]=='F'&&d[2]=='D'||b[2]=='D'&&d[2]=='F'||b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'))cout<<1;
		else cout<<0;
	}
	else cout<<"0000";
	return 0;
}
