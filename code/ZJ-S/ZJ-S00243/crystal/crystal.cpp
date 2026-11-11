#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N],c[N],s[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	s[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=2;i<=n;i++){
		int tans=0;
		if(a[i]*i-s[i]<=m) tans=i;
		else{
			int l=1,r=i-1;
			while(l<=r){
				int mid=l+r>>1;
				if(a[i]*mid-(s[i]-s[i-mid])<=m){
					tans=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
		}
		ans=max(ans,tans);
	}
	cout<<ans;
	return 0;
}