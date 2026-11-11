#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],pre[500001],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long res=-1,l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(a[i]*(i-mid+1)-pre[i]+pre[mid-1]<=m){
				res=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
} 
