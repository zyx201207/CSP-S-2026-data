// Trick||Treat!
#include<bits/stdc++.h>
using namespace std;
const int N=10005;
string a,b,c,d;
int l,r,nm;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	mp['A']=1;
	mp['B']=1;
	mp['C']=1;
	mp['D']=2;
	mp['F']=2;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&(b[0]==d[0]&&b[1]==d[1])) cout<<1,nm=1;
	else cout<<0;
	if(nm&&(mp[b[2]]==mp[d[2]])) cout<<1,r=1;
	else cout<<0;
	if(a==c&&r){
		if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')) l=0;
		else l=1;
	}
	else l=0;
	if(l) cout<<1;
	else cout<<0;
	return 0;
} 
