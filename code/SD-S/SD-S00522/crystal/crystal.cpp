#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[500010];
int ans;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		while(a[i]==a[i+1]){
			i++;
		}
		long long k=m+sum[i];
		int l=1,r=i,mid;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)+sum[mid-1]==k){
				l=mid;
				break;
			}
			if(a[i]*(i-mid+1)+sum[mid-1]<k){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

