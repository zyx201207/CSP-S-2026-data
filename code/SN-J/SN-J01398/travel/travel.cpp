#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define pb push_back
string a,b,c,d;
inline void Solve(){
	cin>>a>>b>>c>>d;
	bool v=(a==c);
	cout<<v;
	if(v==0){
		cout<<"000";
		return;
	}
	bool k;
	if(b[0]==d[0]&&b[1]==d[1]) k=1;
	else k=0;
	cout<<k&&v;
	bool p;
	if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')) p=true;
	if(b[2]=='A'&&d[2]=='B')p=true;
	if(b[2]=='B'&&d[2]=='A')p=true;
	if(b[2]=='A'&&d[2]=='C')p=true;
	if(b[2]=='C'&&d[2]=='A')p=true;
	if(b[2]=='B'&&d[2]=='C')p=true;
	if(b[2]=='C'&&d[2]=='B')p=true;
	if(!k) p=false;
	cout<<p;
	bool e;
	if(abs(b[2]-d[2])==1&&p&&k&&v) e=1;
	else e=0;
	cout<<e;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) Solve();
	return 0;
}
