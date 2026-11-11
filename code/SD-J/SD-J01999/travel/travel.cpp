#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	string rc,rs,xc,xs;
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int rpai=(rs[0]-'0')*10+rs[1]-'0';
	int xpai=(xs[0]-'0')*10+xs[1]-'0';
	int rshu=rs[2]-'A',xshu=xs[2]-'A';
	int fr=-1,fx=-1;
	if(rshu>=0&&rshu<=2)fr=1;
	if(xshu>=0&&xshu<=2)fx=1;
	if(rpai==xpai)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(fr==fx)cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(xshu-rshu)==1)cout<<1;
	else cout<<0;
	return 0;
} 
