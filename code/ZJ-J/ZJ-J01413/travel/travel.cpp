#include <bits/stdc++.h>
using namespace std;
int f[1000];string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;f['A']=f['B']=f['C']=1;f['F']=f['D']=2;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b.substr(0,2)==d.substr(0,2))cout<<1;
	else cout<<0;
	if(a==c&&b.substr(0,2)==d.substr(0,2)&&f[b[2]]==f[d[2]])cout<<1;
	else cout<<0;
	if(a==c&&b.substr(0,2)==d.substr(0,2)&&f[b[2]]==f[d[2]]&&abs(b[2]-d[2])==1)cout<<1;
	else cout<<0;
	return 0;
}

