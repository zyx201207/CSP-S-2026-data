#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,s[N],ans=1;
int cq1[N],cq2[N];
int get_sum(int l,int r)
{
	int x=cq1[r]*(r-l)-(cq2[r-1]-cq2[l-1]);
	return x;
}
void work(int x)
{
	int l=x,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int w=get_sum(x,mid);
		if(w<=m) {ans=max(ans,mid-x+1);l=mid+1;}
		else r=mid-1;
	}
}
signed main(void)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>s[i];
	if(n==1) {cout<<1;return 0;}
	sort(s+1,s+n+1);
	for(int i=2;i<=n;++i) 
	{
		cq1[i]=s[i]-s[i-1]+cq1[i-1];
		cq2[i]=cq1[i]+cq2[i-1];
	}
	for(int i=1;i<n;++i) work(i);
	cout<<ans;
}
