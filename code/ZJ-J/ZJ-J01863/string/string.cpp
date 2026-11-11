#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n;
ll a[N],sum=0;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>a[i]>>c[i],sum+=a[i];
	ll ans=0,l=0,mid=(sum+1)>>1;
	int i=1,j=n;
	while(l<=mid&&i<=j)
	{ 
		if(c[i]!=c[j])
			l+=min(a[i],a[j]),ans+=min(a[i],a[j]);
		else
			l+=min(a[i],a[j]);
		if(a[i]>a[j])
			a[i]-=a[j],j--;
		else if(a[i]==a[j])
			i++,j--;
		else
			a[j]-=a[i],i++;
	}
	cout<<ans;
	return 0;
}
