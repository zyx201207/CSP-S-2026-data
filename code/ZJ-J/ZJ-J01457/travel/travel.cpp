// 8:30 8:42 
#include<bits/stdc++.h>
using namespace std;
int a,b;
string s,t;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	int x,y;
	x=0,y=0;
	x=(s[0]-'0')*10+(s[1]-'0');
	y=(t[0]-'0')*10+(t[1]-'0');
	if(a!=b) cout<<"0000";
	else if(a==b){
		cout<<"1";
		if(x==y){
			cout<<"1";
			if(s[2]<='C'&&t[2]<='C'||s[2]>='D'&&t[2]>='D'){
				cout<<"1";
				char aa=s[2],bb=t[2];
				if(aa>bb)swap(aa,bb);
				if(aa=='A'&&bb=='B'||aa=='B'&&bb=='C'||aa=='D'&&bb=='F'){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else{
			cout<<"000";
		}
	}
	return 0;
}
/**
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
**/
