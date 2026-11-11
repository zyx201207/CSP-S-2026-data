#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,w,mid,x,a[500010],b[500010],bao,ma;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[n]-a[i],b[i]=b[i-1]+b[i];
	for(int i=1;i<=n;i++){
		t=1;w=i-1;bao=i+1;
		while(t<=w){
			mid=(t+w)/2;
			x=b[i]-b[mid-1]-(i-mid+1)*(a[n]-a[i]);
			if(x<=m) bao=mid,w=mid-1;
			else t=mid+1;
		}
		ma=max(ma,i-bao+1);
	}
	cout<<ma;
	return 0;
}