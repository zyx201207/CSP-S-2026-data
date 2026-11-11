#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b) cout<<"1";
	else cout<<"0";
	if(c[0]==d[0] and c[1]==d[1] and c!=d) cout<<"1";
	else cout<<"0";
	if(c[2]=='A' and d[2]=='B') cout<<"1";
	else if(c[2]=='B' and d[2]=='C') cout<<"1";
	else if(c[2]=='A' and d[2]=='C') cout<<"1";
	else if(c[2]=='D' and d[2]=='E') cout<<"1";
	else if(d[2]=='A' and c[2]=='B') cout<<"1";
	else if(d[2]=='B' and c[2]=='C') cout<<"1";
	else if(d[2]=='A' and c[2]=='C') cout<<"1";
	else if(d[2]=='D' and c[2]=='E') cout<<"1";
	else cout<<"0";
	if(int(c[2])-int(d[2])==1 and c[2]!='C' and c[2]!='D' and d[2]!='C' and d[2]!='D') cout<<"1";
	else if(int(d[2])-int(c[2])==1 and c[2]!='C' and c[2]!='D' and d[2]!='C' and d[2]!='D') cout<<"1"; 
	else cout<<"0"; 
	return 0;
}
