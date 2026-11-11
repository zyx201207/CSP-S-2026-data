#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else{
		cout<<"0000"<<'\n';
		return 0;
	}
	if((b[0]+b[1])==(d[0]+d[1])){
		cout<<1;
	}else{
		cout<<"000"<<'\n';
		return 0;
	}
	char x=b[2],y=d[2];
//	cout<<x<<' '<<y<<'\n';
	if((x>'C'&&y<='C')||(x<='C'&&y>'C')){
		cout<<"00"<<'\n';return 0;
	}else cout<<1;
	if(x=='D'&&y=='F')cout<<1;
	else if(x=='F'&&y=='D')cout<<1;
	else if(x=='A'&&y=='B')cout<<1;
	else if(x=='B'&&y=='A')cout<<1;
	else if(x=='B'&&y=='C')cout<<1;
	else if(x=='C'&&y=='B')cout<<1;
	else cout<<0;
	cout<<'\n';
	return 0;
}

