#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N],pre[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=0;
		pre[i]=pre[i-1]+a[i];
		while(l<=r){
			int mid=(l+r)>>1;
			if(pre[i]-pre[mid-1]+m>=a[i]*(i-mid+1)){
				res=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/