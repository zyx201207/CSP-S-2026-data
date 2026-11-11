#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int ans1,ans2,ans3,ans4;
	if(a[0]==c[0]&&a[1]==c[1]) ans1=1;
	else ans1=0;
	if(ans1&&b[0]==d[0]&&b[1]==d[1]) ans2=1;
	else ans2=0;
	char fit1,fit2;
	if(b[2]=='D'||b[2]=='F') fit1='l';
	else fit1='r';
	if(d[2]=='D'||d[2]=='F') fit2='l';
	else fit2='r';
	if(ans2&&fit1==fit2) ans3=1;
	else ans3=0;
	char x=b[2],y=d[2];
	if(ans3&&((x=='A'&&y=='B')||(x=='B'&&y=='A')||
	(x=='C'&&y=='B')||(y=='C'&&x=='B')||
	(x=='F'&&y=='D')||(x=='D'&&y=='C'))) ans4=1;
	else ans4=0;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
