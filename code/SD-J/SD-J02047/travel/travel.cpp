#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,c3,c4;
signed main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<1;
	else cout<<0;
	if(c1==c3&&c2.substr(0,2)==c4.substr(0,2)) cout<<1;
	else cout<<0;
	if(c1==c3&&((c2[2]>='D'&&c4[2]>='D')||(c2[2]<='C'&&c4[2]<='C'))&&c2.substr(0,2)==c4.substr(0,2)) cout<<1;
	else cout<<0;
	if(c1==c3&&c2.substr(0,2)==c4.substr(0,2)&&((c2[2]>='D'&&c4[2]>='D')||(c2[2]<='C'&&c4[2]<='C'))&&abs(c2[2]-c4[2])==1) cout<<1;
	else cout<<0;
}
