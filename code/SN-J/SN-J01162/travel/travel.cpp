#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	string su1=s1.substr(0,2),su2=s2.substr(0,2);
	if(su1==su2&&(c1==c2)) cout<<1;
	else cout<<0;
	int s1n=s1[2]-'A',s2n=s2[2]-'A';
	if(su1==su2&&(c1==c2)&&(s1n<=2&&s2n<=2)||(s1n>2&&s2n>2)) cout<<1;
	else cout<<0;
	if(su1==su2&&(c1==c2)&&abs(s1n-s2n)==1&&((s1n<=2&&s2n<=2)||(s1n>2&&s2n>2))) cout<<1;
	else cout<<0;
	return 0;
}
