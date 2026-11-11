#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=n-i+1;
		while(l<r){
			int mid=l+r+1>>1;
			if(a[mid+i-1]*(mid-1)-(sum[mid+i-2]-sum[i-1])>m)r=mid-1;
			else l=mid;
		}
		ans=max(ans,(long long)l);
	}
	cout<<ans;
	return 0;
}
