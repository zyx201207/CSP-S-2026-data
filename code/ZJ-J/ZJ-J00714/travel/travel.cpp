#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<(a==c)<<(a==c&&b[0]==d[0]&&b[1]==d[1]);
	cout<<(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]-'A'<=2&&d[2]-'A'<=2)||(b[2]-'A'>2&&d[2]-'A'>2)));
	cout<<(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]-'A'<=2&&d[2]-'A'<=2)||(b[2]-'A'>2&&d[2]-'A'>2))&&abs(b[2]-d[2])==1);
	return 0;
}
