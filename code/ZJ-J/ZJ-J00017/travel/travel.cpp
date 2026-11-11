#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c1,c2;
string s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	int a=(c1==c2),b=a*(s1[0]==s2[0]&&s1[1]==s2[1]),c=b*(s1[2]<'D'&&s2[2]<'D'||s1[2]>'C'&&s2[2]>'C');
	cout<<a<<b<<c<<(s1[2]<'D'&&s2[2]<'D'&&c*abs(s1[2]-s2[2])==1||s1[2]>'C'&&s2[2]>'C');
	return 0;
}