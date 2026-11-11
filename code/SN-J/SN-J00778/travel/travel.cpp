//SN-J00778 尚玥轩 西安星光实验学校 
#include<bits/stdc++.h>
using namespace std;
struct a{
	string c;
	string s;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a r,x;
	cin>>r.c>>r.s>>x.c>>x.s;
	if(r.c==x.c) cout<<1;
	else cout<<0;
	if(r.s[0]==x.s[0] && r.s[1]==x.s[1] && r.c==x.c) cout<<1;
	else cout<<0;
	if((r.s[0]==x.s[0] && r.s[1]==x.s[1] && r.c==x.c) && (((r.s[2]>='A' && r.s[2]<='C') && (x.s[2]>='A' && x.s[2]<='C')) || ((r.s[2]=='D' || r.s[2]=='F') && (x.s[2]=='D' || x.s[2]=='F')))){
		cout<<1;
	}
	else cout<<0;
	if(((r.s[2]-'A'+1)==x.s[2]-'A' && (r.s[2]!='D' && x.s[2]!='D')) || ((r.s[2]=='D' && x.s[2]=='F') || (r.s[2]=='F' && x.s[2]=='D'))) cout<<1;
		else cout<<0;
	return 0;
}
