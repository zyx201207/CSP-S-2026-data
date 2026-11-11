#include<bits/stdc++.h>
using namespace std;
long long n,MIN,ans,l,r,a[200010];
char ch[200010];
int main()
{
	freopen("string.in","r",stdin);
//	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i]>>ch[i];
    l=1;r=n;ans=0;
    while(l<r)
    {
    	MIN=min(a[l],a[r]);
    	if(ch[l]!=ch[r]) ans+=MIN;
    	a[l]-=MIN;
    	a[r]-=MIN;
    	if(a[l]==0) l++;
    	if(a[r]==0) r--;
	}
	cout<<ans<<"\n";
    return 0;
} 
