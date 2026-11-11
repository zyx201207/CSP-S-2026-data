#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10];
string s1,s2,c1,c2;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a[1]=1;
	if(a[1]&&s1.substr(0,2)==s2.substr(0,2)) a[2]=1;
	if(a[2]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))) a[3]=1;
	if(a[3]&&abs(s1[2]-s2[2])==1) a[4]=1;
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}

