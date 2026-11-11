#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000000];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	ll l=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>a[i]>>c;
		for(ll j=1;j<=a[i];j++)
			s+=c;
		l+=a[i];
	}
	string s2=s;
	reverse(s.begin(),s.end());
	cout<<s<<' '<<s2<<endl;
	for(int i=0;i<=l/2;i++)
		if(s2[i]!=s[i])
			cnt++;
	cout<<cnt;
	return 0;
}
