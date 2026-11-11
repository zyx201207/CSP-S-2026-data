#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int h[N],n,m,a[N];
int solve(int x){
	int l=x,r=n;
	while(l<r){
		int mid=l+r+1>>1,ans=0;
		ans=h[mid]*(mid-x)-(a[mid-1]-a[x-1]);
		if(ans>m)r=mid-1;
		else l=mid;
	}
	return r-x+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>h[i];
	sort(h+1,h+1+n);
	for(int i=1;i<=n;i++)a[i]=a[i-1]+h[i];
	int mx=-1;
	for(int i=1;i<=n;i++){
		mx=max(mx,solve(i));
	}
	cout<<mx;
	return 0;
}