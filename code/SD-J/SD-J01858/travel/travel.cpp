#include<bits/stdc++.h>
#define int long long
using namespace std;
int fa,fb;
string a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>fa>>a>>fb>>b;
	if(fa==fb){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')){
		cout<<1;
		if((a[2]=='C'&&b[2]=='A')||(b[2]=='C'&&a[2]=='A')){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else if((a[2]=='E'&&b[2]=='D')||(b[2]=='E'&&a[2]=='D')){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
	return 0;
}
