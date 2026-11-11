#include<bits/stdc++.h>
using namespace std;
long long a[550000];
long long sum[550000];
long long m;
int n,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<r){
            mid=(l+r+1)>>1;
            if(a[i]*mid-sum[i]+sum[i-mid]<=m) l=mid;
            else r=mid-1;
        }
        ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}
