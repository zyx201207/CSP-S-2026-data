#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000010];
char c[1000010];
string c1,s1,s2;
int main()
 {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,i,j,s=0,s1=1,ans=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i],s+=a[i];
		for(j=1;j<=a[i];++j)
		{
			c1+=c[i];
		}
	}
	//cout<<c1;
	for(i=0;i<c1.length()-1;++i)
	{
		if(c1[i]==c1[i+1]) s1++;
	}
	if(s1==s)
	{
		cout<<"0";
		return 0;
	}
	else
	{
		for(i=0;i<=s/2-1;++i) if(c1[i]!=c1[s-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
