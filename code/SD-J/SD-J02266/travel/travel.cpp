#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a!=c)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if (b.substr(0,2)!=d.substr(0,2))
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	int x = b[2]-'A',y = d[2]-'A';
	x = min(x,4),y = min(y,4);
	if ((x<3)!=(y<3))
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if (abs(x-y)==1) cout<<1;
	else cout<<0;
	return 0;
} 
