#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,a,c,b;
	cin>>s>>a>>c>>b;
	if(s==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a[2]=='D'||b[2]=='D')&&(a[2]=='C'||b[2]=='C'))
	{
		cout<<"00";
		return 0;
	}
	else{
		cout<<1;
	}
	if((int)abs(a[2]-b[2])==1||((a[2]=='D'||b[2]=='D')&&(a[2]=='F'||b[2]=='F')))
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}