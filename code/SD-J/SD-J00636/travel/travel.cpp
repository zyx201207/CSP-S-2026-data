#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+5;
string s,t,p,q;
int a,b,c,d;
int n,m;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>p>>s>>q>>t;
	a=(p[0]-'0')*10+p[1]-'0';
	b=(q[0]-'0')*10+q[1]-'0';
	c=(s[0]-'0')*10+s[1]-'0';
	d=(t[0]-'0')*10+t[1]-'0';
	n=s[2]-'A'+1;
	m=t[2]-'A'+1;
//	cout<<a<<b<<c<<d<<n<<m;
	if(a==b)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(c==d)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((n<=3&&m<=3)||(n>3&&m>3))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(n-m)==1)cout<<1;
	else cout<<0;
	return 0;
}

