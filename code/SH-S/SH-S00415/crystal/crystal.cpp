#include<bits/stdc++.h>
#define ll long long
#define lll __int128
using namespace std;
const int N=5e5+7;

int n,ans;
ll m,a[N];
lll maxn,cf[N],sum[N],s[N];

void write(lll x) {
	int c[35],p=0;
	while(x!=0) {
		c[p++]=x%10;
		x/=10;
	}
	for(int j=p-1;j>=0;j--)cout<<c[j];
	cout<<endl;
}

bool check(lll mid,lll i) {
	lll x=(i-mid)*sum[i]+sum[i];
	return maxn>=s[mid]-s[i+1]-x;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;maxn=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)cf[i]=a[i]-a[i-1];
	for(int i=n;i>=1;i--)sum[i]=sum[i+1]+cf[i+1];
	for(int i=n;i>=1;i--)s[i]=s[i+1]+sum[i];
	for(int i=1;i<=n;i++) {
		while(a[i+1]==a[i])i++;
		int l=1,r=i,res=i;
		while(l<=r) {
			int mid=(l+r)/2;
			if(check(mid,i)) {
				res=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<'\n';
	return 0;
}
