#include<bits/stdc++.h>
using namespace std;
char a[5],z[5],b[5],y[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>a[0]>>a[1]>>z[0]>>z[1]>>z[2]>>b[0]>>b[1]>>y[0]>>y[1]>>y[2];
	int ra=a[0]*10+a[1],xa=b[0]*10+b[1],rp=z[0]*10+z[1],xp=y[0]*10+y[1];
	char rl=z[2],xl=y[2];
	int rc,xc;
	if(rl=='A'||rl=='B'||rl=='C')	rc=1;
	else	rc=0;
	if(xl=='A'||xl=='B'||xl=='C')	xc=1;
	else	xc=0;
	if(ra==xa){
		cout<<1;
		if(rp==xp){
			cout<<1;
			if(rc==xc){
				cout<<1;
				if(rl-xl==1||xl-rl==1)	cout<<1;
				else	cout<<0;
			}
			else	cout<<"00";
		}
		else	cout<<"000";
	}
	else	cout<<"0000";
	return 0;
}