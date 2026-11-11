#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;

int n;
ll a[N];
char c[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		int tmp=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=tmp;
		a[l]-=tmp;
		a[r]-=tmp;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	printf("%lld",ans);
	return 0;
}
