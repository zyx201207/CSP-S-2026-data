#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	
	a1=(a==c?1:0);
	
	a2=(a1 && b[0]==d[0]&&b[1]==d[1]?1:0);
	
	a3=(a2 && (((b[2]<='C'&&b[2]>='A')&&(d[2]<='C'&&d[2]>='A'))
	||(b[2]>='D'&&b[2]<='E')&&(d[2]>='D'&&d[2]<='E'))?1:0);
	
	if(a3&&((b[2]=='A'&&d[2]=='B') || (b[2]=='B'&&(d[2]=='A'||d[2]=='B'))
	||(b[2]=='C'&&d[2]=='B') || (b[2]=='D'&&d[2]=='E') || (b[2]=='E'&&d[2]=='D'))) a4=1;
	else a4=0;
	
	cout<<a1<<a2<<a3<<a4;
	
	return 0;
}

