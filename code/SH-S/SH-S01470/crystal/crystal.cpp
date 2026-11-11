#include<bits/stdc++.h>
using namespace std;
const int N=500005;
#define ll long long
ll m,a[N],b[N],s[N],tmp;
int n,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i) b[i]=a[i+1]-a[i],s[i]=s[i-1]+b[i];
	int j=1;
	for(int i=1;i<n;++i)
	{	
		tmp+=b[i]*(i-j+1);
		while(tmp>m) tmp-=s[i]-s[j-1],j++;
		ans=max(ans,i-j+2);
	}
	cout<<ans<<'\n';
	return 0;
}
