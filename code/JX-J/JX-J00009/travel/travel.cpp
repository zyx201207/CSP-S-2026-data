#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]+b[1]==d[0]+d[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int e,f;
	if(b[2]<='C') e=1;
	else e=2;
	if(d[2]<='C') f=1;
	else f=2;
	if(e==f) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(int(b[2])==int(d[2]-1)||int(b[2]-1)==int(d[2])) cout<<1;
	else cout<<0;
	return 0;
}
