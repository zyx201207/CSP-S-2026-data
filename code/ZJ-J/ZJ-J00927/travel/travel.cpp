#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	cout<<(a==c);
	cout<<(a==c && b[0]==d[0] && b[1]==d[1]);
	cout<<(a==c && b[0]==d[0] && b[1]==d[1] && (b[2]<='C' && d[2]<='C' || b[2]>='D' && d[2]>='D'));
	cout<<(a==c && b[0]==d[0] && b[1]==d[1] && (b[2]<='C' && d[2]<='C' && abs(d[2]-b[2])==1 || b[2]>='D' && d[2]>='D'));
	return 0;
}