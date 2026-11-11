#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	string id;
	//spÅÅ,slÁĞ 
	string s,sp;
	char sl;
	//ABC -> 0 DE -> 1
	int ce;
}a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("travel5.in","r",stdin);
//	freopen("travel5.out","w",stdout);
	cin>>a.id>>a.s>>b.id>>b.s;
	a.sp=a.s.substr(0,2);
	a.sl=a.s[2];
	if(a.sl=='F') a.sl='E'; 
	b.sp=b.s.substr(0,2);
	b.sl=b.s[2];
	if(b.sl=='F') b.sl='E';
	a.ce=(a.sl=='D'||a.sl=='E');
	b.ce=(b.sl=='D'||b.sl=='E');
	if(a.id==b.id) cout<<1;
	else cout<<0;
	if(a.id==b.id&&a.sp==b.sp) cout<<1;
	else cout<<0;
	if(a.id==b.id&&a.sp==b.sp&&a.ce==b.ce) cout<<1;
	else cout<<0;
	if(a.id==b.id&&a.sp==b.sp&&a.ce==b.ce&&abs(a.sl-b.sl)==1) cout<<1;
	else cout<<0;
    return 0;
}
