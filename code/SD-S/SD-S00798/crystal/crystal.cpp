#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans,q[500005];
bool hf(int x,int y){
	if(y<=0)y=1; 
	ll c=1ll*a[x]*(x-y+1)-(q[x]-q[y-1]);
	if(c<=m)return 1;
	else return 0;
} 
ll get(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)>>1;
		if(hf(x,mid))r=mid;
		else l=mid+1;
	}
	return x-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
		ans=max(ans,get(i));
	}
	cout<<ans;
	return 0;
}
