#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool aa,bb,cc,dd;
int f[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	aa=(a==c);
	bb=aa&&(b[0]==d[0]&&b[1]==d[1]);
	f[1]=(b[2]=='A'||d[2]=='A');
	f[2]=(b[2]=='B'||d[2]=='B');
	f[3]=(b[2]=='C'||d[2]=='C');
	f[4]=(b[2]=='D'||d[2]=='D');
	f[5]=(b[2]=='F'||d[2]=='F');
	cc=bb&&(f[1]+f[2]+f[3]==2||f[4]+f[5]==2);
	dd=cc&&(f[1]+f[2]==2||f[2]+f[3]==2||f[4]+f[5]==2);
	cout<<aa<<bb<<cc<<dd;
	return 0;
}
