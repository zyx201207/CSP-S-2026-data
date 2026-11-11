#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n;
long long m;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(1LL*a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m){
				res=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		if(res!=-1)ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
} 
