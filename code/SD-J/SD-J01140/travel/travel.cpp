#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
string a,aa,b,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	int x=aa[2]-'A',y=bb[2]-'A';
	if(a==b) cout<<1;
	else cout<<0;
	if(a==b&&aa[0]==bb[0]&&aa[1]==bb[1]) cout<<1;
	else cout<<0;
	if(a==b&&aa[0]==bb[0]&&aa[1]==bb[1]&&((x<3&&y<3)||(x>=3&&y>=3))) cout<<1;
	else cout<<0;
	if(a==b&&aa[0]==bb[0]&&aa[1]==bb[1]&&((x<3&&y<3)||(x>=3&&y>=3))&&abs(x-y)==1) cout<<1;
	else cout<<0;
	return 0;
}
