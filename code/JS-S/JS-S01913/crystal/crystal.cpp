#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],maxn=1,pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=l+((r-l)>>1);
			if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		maxn=max(maxn,i-ans+1);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
