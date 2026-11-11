//SN-S00255
#include<bits/stdc++.h>
using namespace std;
const int fyc=1e6+5;
long long n,s[fyc],sum[fyc],m,ans,tag;
long long merge(int l,int r){//need O(1)
	return (r-l)*s[r]-(sum[r-1]-sum[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+s[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n+1;
		tag=l;
		while(l<=r){
			int mid=(l+r)>>1;
			if(merge(i,mid)<=m) tag=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,tag-i+1);
	}
	cout<<min(ans,n);
	return 0;
}
//latest 17:34:00
