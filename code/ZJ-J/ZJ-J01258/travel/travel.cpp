#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a!=x) printf("0000");
	else if(b[0]!=y[0]||b[1]!=y[1]) printf("1000");
	else if(b[2]>'C'&&y[2]>'C') printf("1111");
	else if(b[2]<'D'&&y[2]<'D'){
		if(b[2]=='B'||y[2]=='B') printf("1111");
		else printf("1110");
	}
	else printf("1100");
	return 0;
}