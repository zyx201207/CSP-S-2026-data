#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000005;

int n,m;
int ans=1;
int a[N],qz[N];

inline int solve(int l,int r){return a[r]*(r-l)-(qz[r-1]-qz[l-1]);}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin.tie(0)->ios::sync_with_stdio(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		qz[i]=qz[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(solve(mid,i)<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<'\n';
	
	return 0;
}
