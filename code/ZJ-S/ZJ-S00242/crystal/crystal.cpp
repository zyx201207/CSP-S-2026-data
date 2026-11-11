#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+5;
ll a[N],sum[N],m;
int n,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	vector<int> t;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)>>1;
			ll tmp=(i-mid)*a[i];
			if(tmp-(sum[i-1]-sum[mid-1])<=m){
				r=mid-1;
				ans=max(ans,i-mid+1);
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
