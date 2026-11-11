#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	ll l=0,r=0;
	ll len=s.size();
	if(len%2){
		l=len/2-1;
		r=len/2+1;
	}
	else{
		l=len/2-1;
		r=len/2;
	}
	ll ans=0;
	for(;l!=-1&&r!=len+1;l--,r++)
	{
		char s1=s[l],s2=s[r];
		if(s1!=s2) ans++;
		
	}
	cout<<ans;
	return 0;
}
