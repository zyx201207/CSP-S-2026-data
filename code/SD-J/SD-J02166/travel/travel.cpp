#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string c1,s1,c2,s2;
bool b1,b2,b3,b4;
signed main(){
	fast;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)b1=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&b1==1)b2=1;
	if(b2==1&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')))b3=1;
	if(b3==1&&((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')))b4=1;
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
