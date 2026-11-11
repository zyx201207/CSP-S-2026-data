#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int e,f;
	e=a[0]*10-'0'+a[1]-'0';
	f=c[0]*10-'0'+c[1]-'0';
	int g,h,i,j;
	g=b[0]*10-'0'+b[1]-'0';
	i=d[0]*10-'0'+d[1]-'0';
	if(b[2]>='A'&&b[2]<='D') h=b[2]-'A'+1;
	else if(b[2]=='F') h=5;
	if(d[2]>='A'&&d[2]<='D') j=d[2]-'A'+1;
	else if(d[2]=='F') j=5;
	int m,n;
	if(h<=3) m=1;
	else m=2;
	if(j<=3) n=1;
	else n=2;
	if(e==f) cout<<1;
	else cout<<0;
	if(e==f&&g==i) cout<<1;
	else cout<<0;
	if(e==f&&g==i&&m==n) cout<<1;
	else cout<<0;
	if(e==f&&g==i&&m==n&&abs(h-j)==1) cout<<1;
	else cout<<0;
	cout<<endl;
	return 0;
}

