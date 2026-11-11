#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
struct node{
	char c;
	ll sum;
};
ll ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	vector<node> a(n+1);
	For(i,1,n)scanf("%lld %c",&a[i].sum,&a[i].c);
	ll l=1,r=n;
	while(l<=r){
		if(a[l].c!=a[r].c)ans+=min(a[l].sum,a[r].sum);
		if(a[l].sum>a[r].sum)
		{
			a[l].sum-=a[r].sum;
			r--;
		}
		else if(a[l].sum<a[r].sum){
			a[r].sum-=a[l].sum;
			l++;
		}
		else{
			l++;r--;
		}
	}
	printf("%lld",ans);
	return 0;
}