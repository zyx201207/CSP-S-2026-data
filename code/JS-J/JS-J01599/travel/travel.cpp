#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d;
char e,f;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&b==d) cout<<1;
	else cout<<0;
	if(a==c&&b==d&&((e<='C'&&f<='C')||(e>='D'&&f>='D'))) cout<<1;
	else cout<<0;
	if(a==c&&b==d&&((e<='C'&&f<='C'&&abs(f-e)==1)||(e>='D'&&f>='D'&&abs(f-e)==1))) cout<<1;
	else cout<<0;
	return 0;
}
