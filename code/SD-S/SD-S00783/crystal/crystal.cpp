#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5e5+10;
ll n,m;
ll a[N],s[N];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)  s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
	  int l=i,r=n+1;
	  while(l+1<r)
	  {
	    int mid=l+r>>1;
	    if(a[mid]*(mid-i+1)-(s[mid]-s[i-1])<=m)  l=mid;
	    else  r=mid;
	  }
	  ans=max(ans,l-i+1);
	}
	cout<<ans<<"\n";
	return 0;
}

