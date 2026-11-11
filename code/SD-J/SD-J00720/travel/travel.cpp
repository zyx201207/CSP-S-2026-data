#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string a,b,c,d,e,f;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>a>>b>>c>>d;
	e=b[0]+b[1];
	f=d[0]+d[1];
	if(a==c)cout<<"1";
	else cout<<"0";
	if(e==f&&a==c)cout<<"1";
	else cout<<"0";
	if(a==c&&e==f&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'&&d[2]<='F'&&b[2]<='F')))cout<<"1";
	else cout<<"0";
	if(a==c&&e==f&&(b[2]-d[2]==1||b[2]-d[2]==-1)&&((b[2]!='C'&&d[2]!='D')&&(d[2]!='C'&&b[2]!='D')))cout<<"1";
	else cout<<"0";
	cout<<endl;
	return 0;
}

