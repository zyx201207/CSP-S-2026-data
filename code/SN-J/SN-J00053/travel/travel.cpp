#include<bits/stdc++.h>
using namespace std;
bool tmp=1;
string a,b;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m) cout<<1;
	else cout<<0,tmp=0;
	if(tmp&&a.substr(0,2)==b.substr(0,2)) cout<<1;
	else cout<<0,tmp=0;
	if(tmp){
	    if(a[2]=='D'&&b[2]=='F') cout<<1;
	    else if(a[2]>'C'||b[2]>'C') cout<<0,tmp=0;
	    else cout<<1;
	}else cout<<0,tmp=0;
	if(tmp&&abs(a[2]-b[2])==1) cout<<1;
	else cout<<0;
	return 0;
} 
