#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
long long cha[500005],sum[500005];
long long m;
int ans;
int dayu(int l,int r,long long t,int p){
//	if(l>=r)return n-1;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
//		if(p==5)cerr<<l<<" "<<r<<" "<<mid<<"\n";
		if(sum[mid]-cha[p]*(p-mid)-sum[p]>m){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
//	if(ans==n)return p;
	return ans+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--){
		cha[i]=a[i+1]-a[i];
		cha[i]+=cha[i+1];
		sum[i]=sum[i+1]+cha[i];
	}
	for(int i=1;i<=n;i++){
//		if(i>1&&a[i]==a[i-1])continue;
		int cnt=i-dayu(1,i,sum[i],i)+1;
		ans=max(ans,cnt);
//		cerr<<i<<" "<<dayu(1,i,sum[i],i)<<"\n";
	}
	cout<<ans;
	return 0;
}