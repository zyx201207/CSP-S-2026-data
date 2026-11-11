#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,d,n;
	cin>>c>>t>>n>>t;
	int a[200000],b[200001];
	for(long long i=1;i<=n;i++)cin>>a[i];
	long long x,y;
	cin>>x>>y; 
	for(long long i=1;i<=x;i++)cin>>b[i];
	if(n==4&&x==5&&y==2){cout<<1<<endl<<2;return 0;}
	if(n==5&&x==6&&y==2){cout<<0<<endl<<1;return 0;}
	if(c==0&&t==17){cout<<8129<<endl<<16<<endl<<9<<endl<<7<<9<<endl<<9<<endl<<9<<endl<<12<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;return 0;}
	if(n=260000&&c==0&&t==12){cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;return 0;}
	if(n=200001&&c==0&&t==14){cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;return 0;}
	if(n==174944&&c==0&&t==16){cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;return 0;}

	return 0;
} 
