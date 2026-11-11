#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10,S=1e8+10;
ll n,a[N],maxai=0,len=0,ans=0;
bool pci=1,pai=1;
char c[N],s[S];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxai=max(maxai,a[i]);
		len+=a[i];
		if(i!=1&&c[i]!=c[i-1])
			pci=0;
		if(i<=n/2&&i!=1&&a[i]!=a[i-1])
			pai=0;
		if(i>(n+1)/2+1&&a[i]!=a[i-1])
			pai=0;
	}
	if(n==1||pci==1){//特判 1：n==1 特判 2：c[i] 全部相同 
		cout<<0;
		return 0;
	}
	if(pai==1&&a[1]==a[n]){//特判 3
		for(ll i=1;i<=n/2;i++)
			if(c[i]!=c[n-i+1])
				ans+=a[i];
		cout<<ans;
		return 0;
	}
	ll x=0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=a[i];j++)
			s[++x]=c[i];
	for(ll i=1;i<=len/2;i++)
		if(s[i]!=s[len-i+1])
			ans++;
	cout<<ans;//当 max(a[i])<=500 时 
	return 0;
}
