#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int	a,b,x,y;
	char xa,ya,za,xb,yb,zb;
	cin>>a>>xa>>ya>>za>>b>>xb>>yb>>zb;
	x=(xa-'0')*10+(ya-'0');
	y=(xb-'0')*10+(yb-'0');
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if(za=='A'||za=='B'||za=='C'){
				if(zb=='A'||zb=='B'||zb=='C'){
					cout<<1;
					if(zb-za==1||zb-za==-1) cout<<1;
					else cout<<0;
				}
				else cout<<0<<0;
			}
			else{
				if(zb=='D'||zb=='F'){
					cout<<1<<1;
				}
				else cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}

