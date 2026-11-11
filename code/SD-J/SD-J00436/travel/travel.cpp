#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(c[0]!=cc[0]||c[1]!=cc[1]){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	if(s[0]!=ss[0]||s[1]!=ss[1]){
		cout<<"000";
		return 0;
	}
	else{
		cout<<1;
	}
	if(s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C'){
		cout<<1;
	}
	else if(s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	int x=abs(s[2]-ss[2]);
	if(x==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
