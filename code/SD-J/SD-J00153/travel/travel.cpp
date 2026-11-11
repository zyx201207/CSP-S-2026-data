#include<bits/stdc++.h>
using namespace std;
#define int long long
string ra,rb,xa,xb;
bool check3(){ 
	return ( (rb[2]>='A' && rb[2]<='C') && (xb[2]>='A' && xb[2]<='C') ) || ( (rb[2]>='D' && rb[2]<='E') && (xb[2]>='D' && xb[2]<='E') );
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ra>>rb>>xa>>xb;
	if(ra==xa)cout<<1;
	else cout<<0;
	if(ra==xa && (rb[0]==xb[0] && rb[1]==xb[1]))cout<<1;
	else cout<<0;
	if(ra==xa && (rb[0]==xb[0] && rb[1]==xb[1]) && check3())cout<<1;
	else cout<<0;
	if(ra==xa && (rb[0]==xb[0] && rb[1]==xb[1]) && check3() && abs(rb[2]-xb[2])==1)cout<<1;
	else cout<<0;
	return 0;
} 
