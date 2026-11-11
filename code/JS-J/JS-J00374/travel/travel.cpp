#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string x=b.substr(0,2),y=d.substr(0,2);
	//cout<<x<<' '<<y<<' ';
	if(x==y) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	//cout<<b[b.size()-1];
	if((b[b.size()-1]>='A'&&b[b.size()-1]<='C'&&d[d.size()-1]>='A'&&d[d.size()-1]<='C')||(b[b.size()-1]=='D'&&d[d.size()-1]=='F')||(b[b.size()-1]=='F'&&d[d.size()-1]=='D')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[b.size()-1]-d[d.size()-1])==1) cout<<1;
	else cout<<0;
	return 0;
}
