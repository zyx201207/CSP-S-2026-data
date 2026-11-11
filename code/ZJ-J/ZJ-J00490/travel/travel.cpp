#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,cc,p,pp;
char s,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>p>>s>>cc>>pp>>ss;
	if(c!=cc){
		cout<<"0000";
	}
	else if(p!=pp){
		cout<<1000;
	}
	else if(s<='C'&&ss>'C'||s>'C'&&ss<='C'){
		cout<<1100;
	}
	else if(s+1!=ss&&s-1!=ss){
		cout<<1110;
	}
	else cout<<1111;
	return 0;
}
