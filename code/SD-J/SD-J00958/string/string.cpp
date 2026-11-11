#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n;
int a[200005];
char s[200005];
int pre[200005];
int ans;
int l,r,len;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>s[i];
		r+=a[i];
		pre[i+1]=pre[i]+a[i]+1;
	}
	len=r;
	l=1;
	for(int i=1,j=n; l<r;)
	{
		if(s[i]==s[j])
		{
			l+=min(a[i],a[j]);
			r-=min(a[i],a[j]);
			if(a[i]>a[j]) a[i]-=a[j],j--;
			else if(a[i]==a[j]) i++,j--;
			else if(a[i]<a[j]) a[j]-=a[i],i++;
		}
		else
		{
			l+=min(a[i],a[j]);
			r-=min(a[i],a[j]);
			ans+=min(a[i],a[j]);
			if(a[i]>a[j]) a[i]-=a[j],j--;
			else if(a[i]==a[j]) i++,j--;
			else if(a[i]<a[j]) a[j]-=a[i],i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

