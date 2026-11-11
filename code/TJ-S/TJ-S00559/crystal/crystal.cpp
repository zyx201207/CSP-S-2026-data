#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	int ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,mid;
		while(l<r){
			mid=(l+r)/2;
			if(sum[i-1]-sum[mid-1]+m<a[i]*(i-mid))
				l=mid+1;
			else
				r=mid;
		}
		if(i-l==1&&a[l]+m<a[i])
			l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
