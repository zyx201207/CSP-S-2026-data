#include<bits/stdc++.h>
using namespace std;
string sa,ta,sb,tb;
bool f(string t){
	if(t[2]<='C')	return false;
	return true;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>sa>>ta>>sb>>tb;
	if(sa==sb)
		cout<<1;
	else
		cout<<0;
	if(sa==sb&&ta[0]==tb[0]&&ta[1]==tb[1])
		cout<<1;
	else
		cout<<0;
	if(sa==sb&&ta[0]==tb[0]&&ta[1]==tb[1]&&f(ta)==f(tb))
		cout<<1;
	else
		cout<<0;
	if(sa==sb&&ta[0]==tb[0]&&ta[1]==tb[1]&&f(ta)==f(tb)&&abs((int)(ta[2]-tb[2]))==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
