#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000001;
int n,m;
int a[N],pre[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)>>1;
			int now=pre[i]-pre[mid-1];
			int cnt=(i-mid+1)*a[i];
			if(cnt-now<=m) r=mid-1;
			else l=mid+1; 
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
