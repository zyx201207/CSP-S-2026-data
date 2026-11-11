#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5e5+100;
int n,m;
int a[N],pre[N];
signed main(){
	FIO
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) 
		pre[i]=pre[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++) {
		int l=1,r=i-1,A=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-pre[i]+pre[mid-1]<=m) r=mid-1,A=mid;
			else l=mid+1;
		}
		ans=max(ans,i-A+1);
	}
	cout<<ans;
	return 0;
}