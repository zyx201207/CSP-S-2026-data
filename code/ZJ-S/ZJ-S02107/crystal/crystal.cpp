#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],pre[500005],s;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		s=max(s,i-ans+1);
	}
	cout<<s;
	return 0;
}
