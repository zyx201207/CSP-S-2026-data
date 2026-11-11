#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200010;
lla[N],pre[N];
int n,
ll m;
bool cheak(int cnt);
for(int i=cnt;i<n;i++)
{
int l=i-cnt+1;
int r=i;
ll cost=a[r]*cnt-(pre(r)-pre[l-1];
if(cost<=m)
{
	return true;
}	
else
{
	return false;
}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
     cin>>a[i];
	}
	sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
     pre[i]=pre[i-1]+a[i];
     int l=1,r=n;
     int ans=1;
    }
    while(l<=r)
    {
    int mid=(l+r)/2;
    if(check(mid))
    {
    ans=mid;
    l=mid+1;
    }
    else
    {
    r=mid-1;
    }
    }
    cout<<ans<<endl;
    return 0;
}
