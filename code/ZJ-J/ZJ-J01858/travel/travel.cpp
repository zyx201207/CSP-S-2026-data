#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int bb=(b[0]-'0')*10+b[1]-'0',dd=(d[0]-'0')*10+d[1]-'0';
	if(a==c) cout<<"1";
	else 	 cout<<"0";
	
	if(a==c && bb==dd) cout<<"1";
	else   		       cout<<"0";
	
	if(a==c && bb==dd && ((b[2]>'C' && d[2]>'C') || (b[2]<='C' && d[2]<='C'))) cout<<"1";
	else								 									   cout<<"0";
	
	if(a==c && bb==dd && ((b[2]>'C' && d[2]>'C') || (b[2]<='C' && d[2]<='C')) && (((b[2]+1)==d[2]) || ((b[2]-1)==d[2]))) cout<<"1";
	else																												 cout<<"0";
	
	return 0;
}
