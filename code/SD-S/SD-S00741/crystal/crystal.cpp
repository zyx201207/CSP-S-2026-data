#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],q[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,cnt=-1,mid;
		while(l<=r){
			mid=l+r>>1;
			if(1ll*(i-mid+1)*a[i]-(q[i]-q[mid-1])<=m){
				r=mid-1;
				cnt=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
}

