#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500010,inf=1e18;
int n,m,a[maxn],tot=0,s[maxn],ans=0;
struct node
{
	int w,s;
}b[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	b[0]={-inf,0};
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[tot].w) b[tot].s++;
		else b[++tot]={a[i],1};
	}
	for(int i=1;i<=n;i++) s[i]=b[i].w-b[i-1].w;
	int l=0,r=0,cost=0,sum=0,cha=0;
	while(r<tot)
	{
		r++;
		cost+=sum*s[r];
		sum+=b[r].s;
		cha+=s[r];
		while(cost>m)
		{
			sum-=b[l].s;
			cost-=cha*b[l].s;
			cha-=s[l+1];
			l++;
		}
		ans=max(ans,sum+(m-cost)/(cha+s[l]));
	}
	cout<<ans;
	return 0;
}