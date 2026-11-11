#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool b=true,c=true,d=true;
	ll i,j=0,n,m;
	string s,s1;
	cin>>n>>s;
	cin>>m>>s1;
	if(n==m) cout<<"1";
	else cout<<"0",c=false;
	for(i=0;i<2;++i) if(s[i]==s1[i]) j++;
	if(j==2&&c==true) cout<<"1";
	else cout<<"0",d=false;
	if(((s[2]<='C'&&s1[2]<='C')||(s[2]>='D'&&s1[2]>='D'))&&d==true) cout<<"1";
	else cout<<"0",b=false;
	if((s[2]+1==s1[2]||s[2]-1==s1[2])&&b==true) cout<<"1";
	else cout<<"0";
	return 0;
}
