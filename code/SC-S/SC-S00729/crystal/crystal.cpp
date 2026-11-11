#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],n,m,ans,s[N];
bool check(int x,int y){
//	cout<<x<<","<<y<<":";
	int sum=(y-x+1)*a[y];
	sum-=s[y]-s[x-1];
//	cout<<sum<<"\n";
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,i)) r=mid-1;
			else l=mid+1;
		}
		int id=r+1;
		ans=max(ans,i-id+1);
	}
	cout<<ans;
	return 0;
}