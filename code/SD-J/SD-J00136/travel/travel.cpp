#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int num(string s)
{
	return (s[0]-'0')*10+(s[1]-'0');
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,aa,b,bb;cin>>a>>aa>>b>>bb;
	int xx=num(a),yy=num(b);
	if(xx==yy) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	int n=num(aa),m=num(bb);
	if(n==m) cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	int x=(aa[2]-'A'),y=(bb[2]-'A');
	if(x<=2&&y<=2||x>2&&y>2) cout<<1;
	else cout<<0;
	if(x<=2&&y<=2&&abs(y-x)==1||x>2&&y>2) cout<<1;
	else cout<<0;
} 
