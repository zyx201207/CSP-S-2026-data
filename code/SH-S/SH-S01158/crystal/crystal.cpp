#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500114
ll a[N]; 
ll sum[N];
int cnt[302],pos[302];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans2=0;
	if(n<=400000&&a[n]<=100&&a[1]>=-100) {
		for(int i=1;i<=n;i++) {
			a[i]+=102;
			cnt[a[i]]++;
			pos[a[i]]=i;
		}
		for(int i=a[1];i<=a[n];i++) if(pos[i]==0) pos[i]=pos[i-1];
		ans2=1;
		for(int i=a[n];i>=a[1];i--) {
			ll tmp=m;
			if(cnt[i]==0) continue;
			for(int j=pos[i]-1;j>=1;j--) {
				if(tmp<i-a[j]) {
					ans2=max(ans2,pos[i]-j);
					break; 
				}
				tmp-=i-a[j];
				if(j==1) ans2=max(ans2,pos[i]);
			}
		}
		cout<<ans2;
		return 0;
	}
	for(int i=n;i>=1;i--) {//右端点到的位置 
		int l=1,r=i,ans=i;
		while(l<=r) {
			int mid=(l+r)/2;//左端点到的位置
			ll len=i-mid+1;
			ll tmp=a[i]*len-(sum[i]-sum[mid-1]);
			if(tmp<=m) {
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans2=max(i-ans+1,ans2);
	}
	cout<<ans2;
	return 0;
} 
