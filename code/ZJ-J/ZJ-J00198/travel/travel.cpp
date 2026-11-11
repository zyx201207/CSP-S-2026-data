#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1,c2;
char s1,s2;
char k1,k2,m1,m2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>k1>>m1>>s1>>c2>>k2>>m2>>s2;
	if (c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if (c1==c2&&k1==k2&&m1==m2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if (c1==c2&&k1==k2&&m1==m2&&((s1<='C'&&s2<='C')||(s1>='D'&&s2>='D'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if (c1==c2&&k1==k2&&m1==m2&&s1>='D'&&s2>='D'){
		cout<<1;
	}
	else if (c1==c2&&k1==k2&&m1==m2&&s1<='C'&&s2<='C'&&abs(s1-s2)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
