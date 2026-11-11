#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b[2]=='D')
		b[2]='G';
	if(d[2]=='D')
		d[2]='G';
	if(a==c)
		cout<<1;
	else
		cout<<0;
	if(a==c && b[0]==d[0] && b[1]==d[1])
		cout<<1;
	else
		cout<<0;
	if(a==c && b[0]==d[0] && b[1]==d[1] && abs(b[2]-d[2])<3)
		cout<<1;
	else
		cout<<0;
	if(a==c && abs(b[2]-d[2])==1 && b[0]==d[0] && b[1]==d[1])
		cout<<1;
	else
		cout<<0;
	return 0;
}
