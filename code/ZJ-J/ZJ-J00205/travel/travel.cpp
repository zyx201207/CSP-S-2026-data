#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int a,c;
string b,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int x=(b[0]-'0')*10+(b[1]-'0');
	int y=(d[0]-'0')*10+(d[1]-'0');
	if(b[2]>d[2]) swap(b,d);
	bool f0=(a==c);
	bool f1=(f0&&x==y);
	bool f2=(f1&&(b[2]=='D'&&d[2]=='E'||b[2]=='A'&&(d[2]=='B'||d[2]=='C')||b[2]=='B'&&d[2]=='C'));
	bool f3=(f2&&(b[2]=='A'&&d[2]=='B'||b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='E'));
	cout<<f0<<f1<<f2<<f3;
	return 0;
}
// AC rp++