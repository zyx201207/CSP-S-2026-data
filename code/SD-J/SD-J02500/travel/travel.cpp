#include<bits/stdc++.h>
using namespace std;
#define int long long

string a,bb,c,dd;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>bb>>c>>dd;
	
	int n=0,m=0,seatb=0,seatd=0;
	for(int i=0;i<2;i++){
		if(!(a[i]=='0'))n+=a[i]-'0',n*=10;
		if(!(c[i]=='0'))m+=c[i]-'0',m*=10;
		if(!(bb[i]=='0'))seatb+=bb[i]-'0',seatb*=10;
		if(!(dd[i]=='0'))seatd+=dd[i]-'0',seatd*=10;
	}
	
	char b=bb[2],d=dd[2];
	if(b>d)swap(b,d);
	
//-----------------------------------------------------
//	cout<<b<<' '<<d<<' '<<seatb<<' '<<seatd<<' '<<n<<' '<<m<<endl;

	if(n==m)cout<<1;
	else cout<<0;
	if(seatb==seatd&&n==m)cout<<1;
	else cout<<0;
	if(b>='A'&&b<='C'&&d>='A'&&d<='C'&&seatb==seatd&&n==m)cout<<1;
	else if(b>='D'&&b<='F'&&d>='D'&&d<='F'&&seatb==seatd&&n==m)cout<<1;
	else cout<<0;
	if(seatb==seatd&&n==m&&((b=='A'&&d=='B')||(b=='B'&&d=='C')||(b=='D'&&d=='F')))cout<<1;
	else cout<<0;
	
	return 0;
} 
