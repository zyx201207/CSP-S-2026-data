#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,d,c;
bool flag=0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&a==c){
		cout<<1;
		flag=1;
	}
	else cout<<0;
	if(flag&&(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||(d[2]=='D'||d[2]=='E')&&(b[2]=='D'||b[2]=='E'))){
		cout<<1;
	}
	else cout<<0;
	if(flag&&((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))){
		cout<<1;
	}
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
