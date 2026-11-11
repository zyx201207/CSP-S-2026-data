#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	long long aa,bb;
	char s1,s2;
	cin>>c1>>aa>>s1>>c2>>bb>>s2;
	string a=to_string(aa);
	string b=to_string(bb);
	if(c1==c2) cout<<'1';
	else cout<<'0';
	if(a==b&&c1==c2) cout<<'1';
	else cout<<'0';
	if(a==b&&c1==c2&&(s1>'E'&&s2>'E'||s1<'E'&&s2<'E')) cout<<'1';
	else cout<<'0';
	if(a==b&&c1==c2&&(s1>'E'&&s2>'E'||s1<'E'&&s2<'E')&&(s1+1==s2||s1-1==s2)) cout<<'1';
	else cout<<'0';
	return 0;
}
