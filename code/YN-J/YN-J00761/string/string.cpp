#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+5;
int a[maxn];
char c[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);	
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum/=2;
	ll ans=0;
	int l=1,r=n;
	while(l<r)
	{
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		if(l>=r) break;
		int temp=min(a[l],a[r]);
		if(sum>temp)
		{
			sum-=temp;
			a[l]-=temp;
			a[r]-=temp;
			if(c[l]!=c[r]) ans+=temp;
		}else 
		{
			if(c[l]!=c[r]) ans+=sum;
			sum=0;
		} 
		if(sum<=0) break;
	}
	cout<<ans;
	return 0;
}
//6767,思维量有点大,有点像二分,难度:普及-
//预估:100