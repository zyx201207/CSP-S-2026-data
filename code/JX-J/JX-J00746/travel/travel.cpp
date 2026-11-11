#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
int v[10]={1,1,1,0,0};
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if( v[ b[2]-'A' ] == v[ d[2]-'A' ] ) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(b[2]-d[2]==1 || b[2]-d[2]==-1) cout<<1;
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
