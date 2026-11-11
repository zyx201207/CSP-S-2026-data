#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int x=a[2]-a[1];
	bool flag=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x) flag=false;
	}
	if(flag){
		int sum=0;
		int cnt=1;
		for(int i=1;i<=n;i++){
			sum+=x*cnt;
			cnt++;
			if(sum>m){
				cnt--;
				break;
			}
		}
		cout<<cnt;
		return 0;
	}
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		int minn=1e15;
		for(int i=mid;i<=n;i++){
			int sum=0;
			for(int j=i-mid+1;j<=i;j++){
				sum+=a[i]-a[j];
			}
			minn=min(minn,sum);
		}
		if(minn<=m){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}
