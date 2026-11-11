#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e6+10;
int a[N],pre[N];
bool check(int mid,int k){
	int len=k-mid+1;
	int sum=a[k]*len-(pre[k]-pre[mid-1]);
	if(sum<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){ 
		int l=1,r=i-1,best=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)) r=mid-1,best=mid;
			else l=mid+1;
		}
		ans=max(ans,i-best+1);
	}
	cout<<ans;
	return 0;
}
