#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
char t1,t2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	printf(c1==c2?"1":"0");
	printf(c1==c2&&s1.substr(0,2)==s2.substr(0,2)?"1":"0");
	t1=s1[2],t2=s2[2];
	if(t1>t2) swap(t1,t2);
	printf(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((t1=='A'&&t2=='B')||(t1=='A'&&t2=='C')||(t1=='B'&&t2=='C')||(t1=='D'||t2=='F'))?"1":"0");
	printf(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((t1=='A'&&t2=='B')||(t1=='B'&&t2=='C')||(t1=='D'||t2=='F'))?"1":"0");
	return 0;
}
