#include<bits/stdc++.h>
#define int long long 
using namespace std;
string xa,xb,ya,yb;
void f(){
	if(xa==ya) cout<<1;
	else cout<<0;
	if(xa==ya&&xb[0]==yb[0]&&xb[1]==yb[1]) cout<<1;
	else cout<<0;
	if((xa==ya&&xb[0]==yb[0]&&xb[1]==yb[1]&&xb[2]<='C'&&yb[2]<='C')||(xa==ya&&xb[0]==yb[0]&&xb[1]==yb[1]&&xb[2]>='D'&&yb[2]>='D')) cout<<1;
	else cout<<0;
	if((xb[2]<='C'&&yb[2]<='C')||(xb[2]>='D'&&yb[2]>='D')){
		int v=xb[2]-yb[2];
		if(xa==ya&&xb[0]==yb[0]&&xb[1]==yb[1]&&abs(v)<=1) cout<<1;
		else cout<<0;
	}else cout<<0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xa>>xb>>ya>>yb;
	f();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
