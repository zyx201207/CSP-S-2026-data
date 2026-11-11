#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		b[i]=a[i]+b[i-1];
	}
	int l,r,mid,ans=0;
	for(int t=1;t<=n;++t){
		l=t,r=n;
		while(l<r){
			mid=l+r+1>>1;
			if(a[mid]*(mid-t+1)-(b[mid]-b[t-1])<=m) l=mid;
			else r=mid-1;
		}
		ans=max(ans,l-t+1);
	}
	cout<<ans;
	return 0;
}