#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,n,m,ma,a[1000010],f[1000010];
int pd(int x){
	int t,w,mid,bao;
	t=1;w=i;
	while(t<=w){
		mid=(t+w)/2;
		if(a[x]*(x-mid+1)-(f[x]-f[mid-1])<=m){
			bao=x-mid+1;
			w=mid-1;
		}
		else
			t=mid+1;
	}
	return bao;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
		f[i]=f[i-1]+a[i];
	for(i=1;i<=n;i++)
		ma=max(ma,pd(i));
	cout<<ma;
}
