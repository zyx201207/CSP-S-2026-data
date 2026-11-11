#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],pre[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=((l+r)>>1);
			ll v=(ll)((i-mid)*a[i]-(pre[i-1]-pre[mid-1]));
			if(v<=m) r=mid;
			else l=mid+1;
//			cout<<l<<" "<<r<<" "<<v<<"\n";
		}
//		cout<<i-l+1<<" ";
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 0
0 1 1 1 1

5 0
1 1 1 1 0

*/