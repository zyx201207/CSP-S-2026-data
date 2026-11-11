#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500050],sum[500050],ans;
bool check(int x,int i){
	int xsum=sum[i]-sum[x]-(x-1)*(a[i]-a[x]);
	if(xsum>m)
		return 0;
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=2;i<=n;i++){
		while(a[i]==a[i+1]&&i+1<=n){
			i++;
		}
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid;
			}
			else
				l=mid+1;
		}
		int ansi=i-r+1;
		ans=max(ans,ansi);
	}
	cout<<ans<<endl;
}
