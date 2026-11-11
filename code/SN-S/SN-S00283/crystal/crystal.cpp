//SN-S00283 Aapwp gxyz
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],s[maxn],ans;

bool check(int x,int mid){
	int t=(x-mid+1)*a[x],q=s[x]-s[mid-1];
	if(t-q<=m) return 1;
	return 0;
}
int find(int x){
	int l=1,r=x,pos=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(x,mid)) r=mid-1,pos=mid;
		else l=mid+1;
	}
	return pos; 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int t=find(i);
		ans=max(ans,i-t+1);
	}
	cout<<ans<<'\n';
}
