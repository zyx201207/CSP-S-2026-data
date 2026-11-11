#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m,a[N],s[N];
ll val(int x,int y){
	ll tot=(y-x+1)*a[y];
	ll cur=s[y]-s[x-1];
	return tot-cur;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
	  int l=1,r=i,res=0;
	  bool v=false;
	  while(l<=r){
	    int mid=(l+r)>>1;
	    if(val(mid,i)<=m) v=true,res=mid,r=mid-1;
	    else l=mid+1;
	  }
	  if(v) ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}