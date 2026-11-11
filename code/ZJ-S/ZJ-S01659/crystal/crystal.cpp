#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N=5e5+5;
int a[N],n,b[N],m,sum[N],ans;

int32_t main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,res=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m){
				res=mid;r=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(res!=-1) ans=max(ans,i-res+1);
	}
	cout<<ans;
}