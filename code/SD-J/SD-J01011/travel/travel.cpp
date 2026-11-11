#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	int ida=0,idb=0;
	for(int i=0;i<a.size();i++) ida=ida*10+a[i]-'0';
	for(int i=0;i<c.size();i++) idb=idb*10+c[i]-'0';
	if(ida!=idb)
	{
		cout<<"0000";
		return 0;
	}
	ida=0;
	idb=0;
	for(int i=0;i<2;i++) ida=ida*10+b[i]-'0';
	for(int i=0;i<2;i++) idb=idb*10+d[i]-'0';
	if(ida!=idb)
	{
		cout<<"1000";
		return 0;
	}
	char e=b[2],f=d[2];
	if(e>f) swap(e,f);
	if(e<='C'&&f>='D')
	{
		cout<<"1100";
		return 0;
	}
	if((f-e)==1||(f=='F'&&e=='D'))
	{
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
