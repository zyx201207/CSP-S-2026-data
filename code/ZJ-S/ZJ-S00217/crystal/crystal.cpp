#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],pre[500005],mx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int l=1;
	for(int r=1;r<=n;r++){
		while((r-l+1)*a[r]-pre[r]+pre[l-1]>m and l<r)l++;
		mx=max(mx,r-l+1);
	}cout<<mx;
	return 0;
}
